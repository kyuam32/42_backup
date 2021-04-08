/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:54:33 by namkyu            #+#    #+#             */
/*   Updated: 2021/04/07 19:31:41 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char *remove_space(char *str)
{
	char *ret;
	int i;
	int space;

	i = 0;
	space = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			space++;
	}
	ret = (char *)malloc(sizeof(char) * (i - space + 1));
	ret[i - space + 1] = 0;
	i = 0;
	while (*str)
	{
		if (*str != ' ')
			ret[i] = *str;
		str++;
		i++;
	}
	return (ret);
}

void ft_free(void *target)
{
	if (target != NULL)
		free(target);
	target = NULL;
}

void v_put(t_vector *vec, int x_input, int y_input)
{
	vec->x = (double)x_input;
	vec->y = (double)y_input;
}

int is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == 'E' || c == 'W' || c == 'S' || c == 'N' || c == ' ')
		return (1);
	return (0);
}

void player_dir_set(t_data *data, char c, int row, int col)
{
	if (data->player.locate == 0)
	{
		data->player.locate = c;
		if (c == 'E')
		{
			data->player.dir.x = 1;
			data->player.dir.y = 0;
		}
		else if (c == 'W')
		{
			data->player.dir.x = -1;
			data->player.dir.y = 0;
		}
		else if (c == 'S')
		{
			data->player.dir.x = 0;
			data->player.dir.y = 1;
		}
		else if (c == 'N')
		{
			data->player.dir.x = 0;
			data->player.dir.y = -1;
		}
		data->player.axis.x = col + 0.5;
		data->player.axis.y = row + 0.5;
	}
	else
		exit_process(data, MAP_DATA_CORRUPTED + 3);
}