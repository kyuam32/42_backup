/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:42:34 by namkyu            #+#    #+#             */
/*   Updated: 2021/03/19 18:23:51 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double line_distance(t_data *data, double x_dir, double y_dir)
{
	t_player *player = &data->player;
	double x_delta;
	double y_delta;
	double x_distance;
	double y_distance;
	double distance;
	int x_step;
	int y_step;
	int x_map = (int)player->x_axis;
	int y_map = (int)player->y_axis;
	int hit = 0;

	x_delta = fabs(1 / x_dir);
	y_delta = fabs(1 / y_dir);
	if (x_dir >= 0)
	{
		x_step = 1;
		x_distance = fabs((ceil(player->x_axis) - player->x_axis) * x_delta);
	}
	else
	{
		x_step = -1;
		x_distance = fabs((player->x_axis - floor(player->x_axis)) * x_delta);
	}
	if (y_dir >= 0)
	{
		y_step = 1;
		y_distance = fabs((ceil(player->y_axis) - player->y_axis) * y_delta);
	}
	else
	{
		y_step = -1;
		y_distance = fabs((player->y_axis - floor(player->y_axis)) * y_delta);
	}
	while (hit == 0)
	{
		if (x_distance < y_distance)
		{
			x_map += x_step;
			x_distance += x_delta;
			data->draw.side = VIRTICAL_SIDE;
		}
		else
		{
			y_map += y_step;
			y_distance += y_delta;
			data->draw.side = HORIZOTAL_SIDE;
		}
		if (data->draw.side == VIRTICAL_SIDE)
			distance = x_distance - x_delta;
		else
			distance = y_distance - y_delta;
		if ((data->draw.tile = data->mini_map.map[y_map][x_map]) > 0)
		{
			hit = 1;
			data->cam.dist = distance;
			draw_rectangle(data, x_map, y_map, 0xFF0000);
		}
	}
	return (distance);
}

void ray_casting(t_data *data)
{
	t_cam *cam = &data->cam;
	t_draw *draw = &data->draw;
	double distance;
	double cur_dir;

	cam->FOV = DEG_TO_RAD(60);
	cam->FOV_precision = data->resolution_width / 5;
	cam->curr_precision = 0;

	cur_dir = cam->FOV / 2 * -1;

	while (cur_dir < cam->FOV / 2)
	{
		cam->x_dir = data->player.x_dir * cos(cur_dir) - data->player.y_dir * sin(cur_dir);
		cam->y_dir = data->player.x_dir * sin(cur_dir) + data->player.y_dir * cos(cur_dir);
		line_distance(data, cam->x_dir, cam->y_dir);
		draw_graphic(data);
		draw_line_minimap(data, data->player.x_axis, data->player.y_axis,
						  data->player.x_axis + cam->dist * cam->x_dir,
						  data->player.y_axis + cam->dist * cam->y_dir);
		cam->curr_precision++;
		cur_dir += cam->FOV / cam->FOV_precision;
	}
}
