/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:38:54 by namkyu            #+#    #+#             */
/*   Updated: 2021/03/22 14:42:00 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void m_map_grid(t_data *data)
{
	int i;
	int j;
	int h_scale = data->map.h_scale;
	t_minimap *map = &data->map;
	i = 0;
	while (i < map->col)
	{
		drawVLine(data, map->h_offset, map->h_offset + map->row * map->cub_height, i * map->cub_width);
		i++;
	}
	drawVLine(data, map->h_offset, map->h_offset + map->row * map->cub_height, i * map->cub_width - 1);
	j = 0;
	while (j < map->row)
	{
		drawHLine(data, 0, map->col * map->cub_width, data->resolution_height * h_scale + j * map->cub_height);
		j++;
	}
	drawHLine(data, 0, map->col * map->cub_width, data->resolution_height * h_scale + j * map->cub_height - 1);
}

void draw_line_minimap(t_data *data, double x_start, double y_start, double x_end, double y_end)
{
	int y_axis_offset = data->resolution_height / 2;
	data->draw.x_s = x_start * data->map.cub_width;
	data->draw.y_s = y_start * data->map.cub_height + y_axis_offset;
	data->draw.x_e = x_end * data->map.cub_width;
	data->draw.y_e = y_end * data->map.cub_height + y_axis_offset;
	data->draw.color = 0x00FFFF;
	draw_line(data);
}

void draw_rectangle(t_data *data, int x, int y, int color)
{
	int i;
	int j;
	t_img *img = &data->img;

	x *= data->map.cub_width;
	y *= data->map.cub_height;
	y += data->resolution_height / 2;
	i = 0;
	while (i < data->map.cub_height)
	{
		j = 0;
		while (j < data->map.cub_width)
		{
			img->data[(y + i) * (img->size_l / 4) + (j + x)] = color;
			j++;
		}
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
	t_player *player = &data->player;
	int y_axis_offset = data->resolution_height / 2;
	int x = data->player.axis.x * data->map.cub_width;
	int y = data->player.axis.y * data->map.cub_height + y_axis_offset;

	data->img.data[(y - 1) * data->img.size_l / 4 + x] = 0xFF0000;
	data->img.data[(y + 1) * data->img.size_l / 4 + x] = 0xFF0000;
	data->img.data[y * data->img.size_l / 4 + x] = 0xFF0000;
	data->img.data[y * data->img.size_l / 4 + x + 1] = 0xFF0000;
	data->img.data[y * data->img.size_l / 4 + x - 1] = 0xFF0000;
}
