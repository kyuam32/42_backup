/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 09:01:00 by michoi            #+#    #+#             */
/*   Updated: 2020/07/19 20:32:28 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int			open_dict(char *dict_name, char *buf)
{
	int		fd;

	fd = open(dict_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	read(fd, buf, BUF_SIZE);
	return (fd);
}

int			allocate_dict(int max_row)
{
	int		i;

	i = 0;
	g_dict = malloc(sizeof(t_dict) * max_row + 1);
	if (g_dict == NULL)
		return (1);
	while (i < (max_row + 1))
	{
		g_dict[i].str = (char *)malloc(sizeof(char) * g_size);
		g_dict[i].key = (char *)malloc(sizeof(char) * g_size);
		g_dict[i].value = (char *)malloc(sizeof(char) * g_size);
		if (g_dict[i].str == NULL || g_dict[i].key == NULL ||\
				g_dict[i].value == NULL)
			return (1);
		i++;
	}
	g_max_dict = max_row;
	return (0);
}

int			split_in_line(int index, char *str)
{
	int		i;

	i = 0;
	while (*str >= '0' && *str <= '9')
		g_dict[index].key[i++] = *(str++);
	g_dict[index].key[i] = '\0';
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*(str++) != ':')
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	i = 0;
	while (*str >= 32 && *str <= 126)
		g_dict[index].value[i++] = *(str++);
	g_dict[index].value[i] = '\0';
	if (*str != '\0')
		return (0);
	return (1);
}

int			split_dict(char *buf)
{
	int		row;
	int		col;

	row = 0;
	col = 0;
	while (*buf)
	{
		if (*buf == '\n')
		{
			g_dict[row].str[col] = '\0';
			if (split_in_line(row, g_dict[row].str) == 0)
				return (0);
			row++;
			col = 0;
		}
		else
			g_dict[row].str[col++] = *buf;
		buf++;
	}
	if (col != 0)
		g_dict[row].str[col] = '\0';
	return (1);
}

int			make_dict(char *dict_name)
{
	int		fd;
	int		max_row;
	int		i;
	char	buf[BUF_SIZE];

	fd = open_dict(dict_name, buf);
	g_size = 0;
	i = 0;
	max_row = 0;
	if (fd == -1)
		return (1);
	while (*(buf + g_size))
		g_size++;
	close(fd);
	while (*(buf + i))
	{
		if (*(buf + i) == '\n')
			max_row++;
		i++;
	}
	if (allocate_dict(max_row))
		return (1);
	if (split_dict(buf) == 0)
		return (1);
	return (0);
}
