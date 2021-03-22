/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixcel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:41:44 by namkyu            #+#    #+#             */
/*   Updated: 2021/03/22 16:58:40 by namkyu           ###   ########.fr       */
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
	double x_start = data->draw.x_s;
	double y_start = data->draw.y_s;
	double x_end = data->draw.x_e;
	double y_end = data->draw.y_e;
	t_img *img = &data->img;

	double deltaX;
	double deltaY;
	double step;

	deltaX = x_end - x_start;
	deltaY = y_end - y_start;
	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(x_end - x_start) > 0.4 || fabs(y_end - y_start) > 0.4)
	{
		img->data[(int)floor(y_start) * (img->size_l / 4) + (int)floor(x_start)] = data->draw.color;
		x_start += deltaX;
		y_start += deltaY;
	}
}

void draw_ray(t_data *data)
{
	data->draw.x_s = data->player.axis.x * data->map.cub_width;
	data->draw.y_s = data->player.axis.y * data->map.cub_height + data->map.h_offset;
	data->draw.x_e = (data->player.axis.x + data->cam.dist * data->cam.dir.x) * data->map.cub_width;
	data->draw.y_e = (data->player.axis.y + data->cam.dist * data->cam.dir.y) * data->map.cub_height + data->map.h_offset;
	data->draw.color = 0x00FFFF;
	draw_line(data);
}
