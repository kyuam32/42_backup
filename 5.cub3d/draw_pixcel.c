/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixcel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:41:44 by namkyu            #+#    #+#             */
/*   Updated: 2021/03/19 18:22:11 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void drawVLine(t_data *data, int y_start, int y_end, int x_start)
{
	t_img *img = &data->img;

	while (y_start < y_end)
	{
		img->data[y_start * img->size_l / 4 + x_start] = data->texture.floor;
		y_start++;
	}
}

void drawHLine(t_data *data, int x_start, int x_end, int y_start)
{
	t_img *img = &data->img;

	while (x_start < x_end)
	{
		img->data[y_start * img->size_l / 4 + x_start] = data->texture.floor;
		x_start++;
	}
}

void draw_line(t_data *data)
{
	double x_start = data->draw.x_s;
	double y_start = data->draw.y_s;
	double x_end = data->draw.x_e;
	double y_end = data->draw.y_e;
	t_img *img = &data->img;

	if (x_start == x_end)
		drawVLine(data, y_start, y_end, x_start);
	if (y_start == y_end)
		drawHLine(data, x_start, x_end, y_start);

	double deltaX;
	double deltaY;
	double step;

	deltaX = x_end - x_start;
	deltaY = y_end - y_start;
	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(x_end - x_start) > 0.1 || fabs(y_end - y_start) > 0.1)
	{
		img->data[(int)floor(y_start) * (img->size_l / 4) + (int)floor(x_start)] = data->draw.color;
		x_start += deltaX;
		y_start += deltaY;
	}
}
