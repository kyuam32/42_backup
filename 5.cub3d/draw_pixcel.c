/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixcel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:41:44 by namkyu            #+#    #+#             */
/*   Updated: 2021/03/22 21:33:17 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_rectangle(t_data *data, int x, int y, int color)
{
	int i;
	int j;

	x *= data->map.cub_width;
	y = y * data->map.cub_height + data->map.h_offset;
	i = 0;
	while (i < data->map.cub_height)
	{
		j = 0;
		while (j < data->map.cub_width)
		{
			data->img.data[(y + i) * (data->img.size_l / 4) + (j + x)] = color;
			j++;
		}
		i++;
	}
}

void draw_line(t_data *data)
{
	t_vector start;
	t_vector end;
	t_vector delta;
	double step;

	start.x = data->draw.start.x;
	start.y = data->draw.start.y;
	end.x = data->draw.end.x;
	end.y = data->draw.end.y;
	delta.x = end.x - start.x;
	delta.y = end.y - start.y;
	step = (fabs(delta.x) > fabs(delta.y)) ? fabs(delta.x) : fabs(delta.y);
	delta.x /= step;
	delta.y /= step;
	while (fabs(end.x - start.x) > 0.5 || fabs(end.y - start.y) > 0.5)
	{
		data->img.data[(int)floor(start.y) * (data->img.size_l / 4) + (int)floor(start.x)] = data->draw.color;
		start.x += delta.x;
		start.y += delta.y;
	}
}

void draw_texture(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			data->img.data[(int)i * (data->img.size_l / 4) + j] = \
			 data->texture.NO_img.data[(int)i * (data->texture.NO_img.size_l / 4) + j];
			j++;
		}
		i++;
	}
}

void draw_3d(t_data *data)
{
	double dist_adj;
	int img_height;
	int height_mid;
	int ray_width;
	int ray_no;
	int i = 0;
	t_draw *draw = &data->draw;

	ray_no = data->cam.curr_precision;
	dist_adj = (data->player.dir.x * data->cam.dir.x + data->player.dir.y * data->cam.dir.y) * data->cam.dist;

	if (dist_adj < 1)
		img_height = data->resolution_height / 2;
	else
		img_height = data->resolution_height / dist_adj / 2;
	height_mid = data->resolution_height / 2;
	ray_width = data->resolution_width / data->cam.FOV_precision;
	while (i < ray_width)
	{
		v_put(&data->draw.start, i + (ray_width * ray_no), 0);
		v_put(&data->draw.end, i + (ray_width * ray_no), height_mid - img_height);
		draw->color = data->texture.ceiling;
		draw_line(data);
		v_put(&data->draw.start, i + (ray_width * ray_no), height_mid - img_height);
		v_put(&data->draw.end, i + (ray_width * ray_no), height_mid + img_height);
		draw->color = draw->side == HORIZOTAL_SIDE ? 0x006400 : 0x008000;
		draw_line(data);
		v_put(&data->draw.start, i + (ray_width * ray_no), height_mid + img_height);
		v_put(&data->draw.end, i + (ray_width * ray_no), height_mid + height_mid);
		draw->color = data->texture.floor;
		draw_line(data);
		i++;
	}
}

void draw_ray(t_data *data)
{
	v_put(&data->draw.start, \
	data->player.axis.x * data->map.cub_width, \
	data->player.axis.y * data->map.cub_height + data->map.h_offset);
	v_put(&data->draw.end, \
	(data->player.axis.x + data->cam.dist * data->cam.dir.x) * data->map.cub_width, \
	(data->player.axis.y + data->cam.dist * data->cam.dir.y) * data->map.cub_height + data->map.h_offset);
	data->draw.color = 0x00FFFF;
	draw_line(data);
}
