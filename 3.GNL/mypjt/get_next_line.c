/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:06:30 by nlee              #+#    #+#             */
/*   Updated: 2021/01/20 15:50:30 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_newline(char *str)
{
	int			i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		mid_process(char **line_storage, char **line)
{
	char		*temp;
	int			idx;

	idx = check_newline(*line_storage);
	(*line_storage)[idx] = '\0';
	*line = ft_strdup(*line_storage);
	/*
	if (ft_strlen(*line_storage + idx + 1) == 0)
	{
	}
	*/
	temp = ft_strdup(*line_storage + idx + 1);
	free(*line_storage);
	*line_storage = temp;
	return(1);
}

int		end_process(char **line_storage, char **line , int read_len)
{
	if (*line_storage && check_newline(*line_storage) >= 0) // multiple \n
		return (mid_process(line_storage, line));
	if (*line_storage) // EOF
	{
		*line = *line_storage;
		*line_storage = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char *line_storage[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	int			read_len;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((read_len = read(fd, buff, BUFFER_SIZE)) > 0) // 버퍼에 읽음과 동시에 EOF check
	{
		buff[read_len] = '\0';
		line_storage[fd] = ft_strjoin(line_storage[fd], buff);
		if (check_newline(line_storage[fd]) >= 0) // \n check
			return (mid_process(&line_storage[fd], line));
	}
	if (read_len < 0)
		return (-1);
	return (end_process(&line_storage[fd], line, read_len));
}
