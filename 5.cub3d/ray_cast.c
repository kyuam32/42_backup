/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:42:34 by namkyu            #+#    #+#             */
/*   Updated: 2021/04/06 10:46:41 by namkyu           ###   ########.fr       */
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
	int x_map = (int)(player->axis.x);
	int y_map = (int)(player->axis.y);
	int hit = 0;
	
	data->draw.tile = 0;
	data->sprite.sp_dist = 0;
	delta.x = (y_dir == 0) ? 0 : ((x_dir == 0) ? 1 : fabs(1 / x_dir));
    delta.y = (x_dir == 0) ? 0 : ((y_dir == 0) ? 1 : fabs(1 / y_dir));

	if (x_dir > 0)
	{
		x_step = 1;
		distance.x = fabs((x_map + 1 - player->axis.x) * delta.x);
	}
	else
	{
		x_step = -1;
		distance.x = fabs((player->axis.x - x_map) * delta.x);
	}
	if (y_dir > 0)
	{
		y_step = 1;
		distance.y = fabs((y_map + 1 - player->axis.y) * delta.y);
	}
	else
	{
		y_step = -1;
		distance.y = fabs((player->axis.y - y_map) * delta.y);
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
		ray_dist = (data->draw.side == VIRTICAL_SIDE) ? (distance.x - delta.x) : (distance.y - delta.y);

		if (data->map.map_arr[y_map][x_map] == '1')
		{
			hit = 1;
			draw_rectangle(data, x_map, y_map, 0x663300);
			data->cam.dist = ray_dist;
		}
		else if (data->map.map_arr[y_map][x_map] == '2')
		{
			data->draw.tile = '2';
			data->sprite.sp_side = data->draw.side;
			if (data->sprite.sp_dist == 0 )
			{
				data->sprite.sp_dist = ray_dist;
				sprite_rad(data, x_map, y_map);
				sprite_ray_rad(data, x_map, y_map);
				data->sprite.sp_adj_dist = hypot((y_map + 0.5 - player->axis.y), (x_map + 0.5 - player->axis.x));
			}
			draw_rectangle(data, x_map, y_map, 0x666699);
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
	data->cam.FOV_precision = data->resolution_width;

	ray_cast(data, draw_3d);
	m_map_wall(data);
	ray_cast(data, draw_ray);
	m_map_grid(data);
	m_map_player(data);
}
