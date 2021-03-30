/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixcel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:41:44 by namkyu            #+#    #+#             */
/*   Updated: 2021/03/30 16:46:54 by namkyu           ###   ########.fr       */
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

void draw_sprite(t_data *data, int x, int y, int height)
{
	t_img *img;
	int wall_x;
	int i;
	int order;
	double deg;
	double repeat;
	double img_mid;

	i = 0;
	deg = DEG_TO_RAD(45);
	img_mid = 120 / 2;
	img = &data->texture.SP_img;
	repeat = 1.0 * 120 / height;
	order = (data->cam.dir.x * data->cam.dir.y) < 0 ? 1 : 0;

	if (data->draw.side == VIRTICAL_SIDE)
	{
		if (order) // start 0
			wall_x = 120 - ((data->player.axis.y + data->cam.sp_dist * data->cam.dir.y) - floor(data->player.axis.y + data->cam.sp_dist * data->cam.dir.y)) / cos(deg) / sqrt(2.0) * 120;
		else // start mid
			wall_x = ((data->player.axis.y + data->cam.sp_dist * data->cam.dir.y) - floor(data->player.axis.y + data->cam.sp_dist * data->cam.dir.y)) / cos(deg) / sqrt(2.0) * 120;
	}
	else
	{
		if (order) //start mid
			wall_x = ((data->player.axis.x + data->cam.sp_dist * data->cam.dir.x) - floor(data->player.axis.x + data->cam.sp_dist * data->cam.dir.x)) / cos(deg) / sqrt(2.0) * 120;
		else //start 0
			wall_x = 120 - ((data->player.axis.x + data->cam.sp_dist * data->cam.dir.x) - floor(data->player.axis.x + data->cam.sp_dist * data->cam.dir.x)) / cos(deg) / sqrt(2.0) * 120;
	}
	while (i < height)
	{
		data->img.data[(int)(y + i) * data->img.size_l / 4 + x] = img->data[(int)(repeat * i) * img->size_l / 4 + wall_x];
		i++;
	}
}

void draw_texture(t_data *data, int x, int y, int height)
{
	t_img *img;
	int wall_x;
	int i;
	double repeat;

	i = 0;
	repeat = 1.0 * 64 / height;

	if (data->draw.side == VIRTICAL_SIDE)
	{
		if (data->cam.dir.x < 0)
		{
			img = &data->texture.WE_img;
			wall_x = 64 - ((data->player.axis.y + data->cam.dist * data->cam.dir.y) - floor(data->player.axis.y + data->cam.dist * data->cam.dir.y)) * 64;
		}
		else
		{
			img = &data->texture.EA_img;
			wall_x = ((data->player.axis.y + data->cam.dist * data->cam.dir.y) - floor(data->player.axis.y + data->cam.dist * data->cam.dir.y)) * 64;
		}
	}
	else
	{
		if (data->cam.dir.y < 0)
		{
			img = &data->texture.NO_img;
			wall_x = ((data->player.axis.x + data->cam.dist * data->cam.dir.x) - floor(data->player.axis.x + data->cam.dist * data->cam.dir.x)) * 64;
		}
		else
		{
			img = &data->texture.SO_img;
			wall_x = 64 - ((data->player.axis.x + data->cam.dist * data->cam.dir.x) - floor(data->player.axis.x + data->cam.dist * data->cam.dir.x)) * 64;
		}
	}
	while (i < height)
	{
		data->img.data[(int)(y + i) * data->img.size_l / 4 + x] = img->data[(int)(repeat * i) * img->size_l / 4 + wall_x];
		i++;
	}
}

void draw_sp(t_data *data)
{
	double dist_adj;
	int img_height;
	int height_mid;
	int ray_width;
	int ray_no;
	int i;
	t_draw *draw = &data->draw;

	ray_no = data->cam.curr_precision;
	dist_adj = data->cam.sp_dist;
	i = 0;
	if (dist_adj < 1)
		img_height = data->resolution_height / 2;
	else
		img_height = data->resolution_height / dist_adj / 2;
	height_mid = data->resolution_height / 2;
	ray_width = data->resolution_width / data->cam.FOV_precision;
	if (data->draw.tile == '2')
	{
		while (i < ray_width)
		{
			draw_sprite(data, i + (ray_width * ray_no), height_mid - img_height, img_height * 2);
			i++;
		}
	}
}

void draw_3d(t_data *data)
{
	double dist_adj;
	int img_height;
	int sp_height;
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
		draw_texture(data, i + (ray_width * ray_no), height_mid - img_height, img_height * 2);
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
	data->draw.color = 0xFFFF99;
	draw_line(data);
}