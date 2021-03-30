/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:54:33 by namkyu            #+#    #+#             */
/*   Updated: 2021/03/26 19:35:05 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void v_put(t_vector *vec, int x_input, int y_input)
{
	vec->x = x_input;
	vec->y = y_input;
}

int is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == 'E' || c == 'W' || c == 'S' || c == 'N' || c == ' ')
		return (1);
	return (0);
}

void player_dir_set(t_data *data, char c, int row, int col)
{
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