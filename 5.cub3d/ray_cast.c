/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:42:34 by namkyu            #+#    #+#             */
/*   Updated: 2021/03/23 15:17:01 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ray_distance(t_data *data, double x_dir, double y_dir)
{
	t_player *player = &data->player;
	t_vector delta;
	t_vector distance;
	double ray_dist;
	int x_step;
	int y_step;
	int x_map = (int)player->axis.x;
	int y_map = (int)player->axis.y;
	int hit = 0;

	delta.x = fabs(1 / x_dir);
	delta.y = fabs(1 / y_dir);
	if (x_dir >= 0)
	{
		x_step = 1;
		distance.x = fabs((ceil(player->axis.x) - player->axis.x) * delta.x);
	}
	else
	{
		x_step = -1;
		distance.x = fabs((player->axis.x - floor(player->axis.x)) * delta.x);
	}
	if (y_dir >= 0)
	{
		y_step = 1;
		distance.y = fabs((ceil(player->axis.y) - player->axis.y) * delta.y);
	}
	else
	{
		y_step = -1;
		distance.y = fabs((player->axis.y - floor(player->axis.y)) * delta.y);
	}
	while (hit == 0)
	{
		if (distance.x < distance.y)
		{
			x_map += x_step;
			distance.x += delta.x;
			data->draw.side = VIRTICAL_SIDE;
		}
		else
		{
			y_map += y_step;
			distance.y += delta.y;
			data->draw.side = HORIZOTAL_SIDE;
		}
		if (data->draw.side == VIRTICAL_SIDE)
			ray_dist = distance.x - delta.x;
		else
			ray_dist = distance.y - delta.y;
		if ((data->draw.tile = data->map.map[y_map][x_map]) > 0)
		{
			hit = 1;
			// draw_rectangle(data, x_map, y_map, 0x00FFFF);
			data->cam.dist = ray_dist;
		}
	}
}

void ray_cast(t_data *data,void (*draw_target)(t_data *))
{
	double cur_dir;

	cur_dir = data->cam.FOV / 2 * -1;
	data->cam.curr_precision = 0;

	while (cur_dir < data->cam.FOV / 2)
	{
		data->cam.dir.x = data->player.dir.x * cos(cur_dir) - data->player.dir.y * sin(cur_dir);
		data->cam.dir.y = data->player.dir.x * sin(cur_dir) + data->player.dir.y * cos(cur_dir);
		ray_distance(data, data->cam.dir.x, data->cam.dir.y);
		draw_target(data);
		data->cam.curr_precision++;
		cur_dir += data->cam.FOV / data->cam.FOV_precision;
	}
}

void ray_initalize(t_data *data)
{
	data->cam.FOV = DEG_TO_RAD(60);
	data->cam.FOV_precision = data->resolution_width / 2;

	ray_cast(data, draw_3d);
	m_map_wall(data);
	ray_cast(data, draw_ray);
	m_map_grid(data);
	m_map_player(data);
}
