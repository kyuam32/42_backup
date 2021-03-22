/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:38:54 by namkyu            #+#    #+#             */
/*   Updated: 2021/03/22 19:10:35 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void m_map_grid(t_data *data)
{
	t_minimap *map = &data->map;
	int i;
	int j;

	i = 0;
	while (i <= map->col)
	{
		v_put(&data->draw.start, i * map->cub_width, map->h_offset);
		v_put(&data->draw.end, i * map->cub_width, map->h_offset + map->row * map->cub_height);
		data->draw.color = 0x000000;
		draw_line(data);
		i++;
	}
	i = 0;
	while (i <= map->row)
	{
		v_put(&data->draw.start, 0, map->h_offset + i * map->cub_height);
		v_put(&data->draw.end, map->col * map->cub_width, map->h_offset + i * map->cub_height);
		data->draw.color = 0x000000;
		draw_line(data);
		i++;
	}
}

void m_map_wall(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->map.row)
	{
		j = 0;
		while (j < data->map.col)
		{
			if (data->map.map[i][j] == 1)
				draw_rectangle(data, j, i, 0xFFFF00);
			else
				draw_rectangle(data, j, i, 0xE0FFFF);
			j++;
		}
		i++;
	}
}

void m_map_player(t_data *data)
{
	int x = data->player.axis.x * data->map.cub_width;
	int y = data->player.axis.y * data->map.cub_height + data->map.h_offset;

	data->img.data[(y - 1) * data->img.size_l / 4 + x] = 0xFF0000;
	data->img.data[(y + 1) * data->img.size_l / 4 + x] = 0xFF0000;
	data->img.data[y * data->img.size_l / 4 + x] = 0xFF0000;
	data->img.data[y * data->img.size_l / 4 + x + 1] = 0xFF0000;
	data->img.data[y * data->img.size_l / 4 + x - 1] = 0xFF0000;
}
