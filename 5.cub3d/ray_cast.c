/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:42:34 by namkyu            #+#    #+#             */
/*   Updated: 2021/03/22 14:41:54 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double ray_distance(t_data *data, double x_dir, double y_dir)
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
			data->cam.dist = ray_dist;
		}
	}
	return (ray_dist);
}

// void ray_radius(t_data *data)
// {
// 	t_cam *cam = &data->cam;
// 	t_draw *draw = &data->draw;

// 	double cur_dir;

// 	while (cur_dir < cam->FOV / 2)
// 	{
// 		cam->dir.x = data->player.dir.x * cos(cur_dir) - data->player.dir.y * sin(cur_dir);
// 		cam->dir.y = data->player.dir.x * sin(cur_dir) + data->player.dir.y * cos(cur_dir);
// 		ray_distance(data, cam->dir.x, cam->dir.y);
// 		draw_graphic(data);
// 		// draw_line_minimap(data, data->player.axis.x, data->player.axis.y,
// 		// 				  data->player.axis.x + cam->dist * cam->dir.x,
// 		// 				  data->player.axis.y + cam->dist * cam->dir.y);
// 		cam->curr_precision++;
// 		cur_dir += cam->FOV / cam->FOV_precision;
// 	}
// }

void ray_casting(t_data *data)
{
	t_cam *cam = &data->cam;
	t_draw *draw = &data->draw;
	double cur_dir;

	cam->FOV = DEG_TO_RAD(60);
	cam->FOV_precision = data->resolution_width / 5;
	cam->curr_precision = 0;
	cur_dir = cam->FOV / 2 * -1;

	while (cur_dir < cam->FOV / 2)
	{
		cam->dir.x = data->player.dir.x * cos(cur_dir) - data->player.dir.y * sin(cur_dir);
		cam->dir.y = data->player.dir.x * sin(cur_dir) + data->player.dir.y * cos(cur_dir);
		ray_distance(data, cam->dir.x, cam->dir.y);
		draw_graphic(data);
		// draw_line_minimap(data, data->player.axis.x, data->player.axis.y,
		// 				  data->player.axis.x + cam->dist * cam->dir.x,
		// 				  data->player.axis.y + cam->dist * cam->dir.y);
		cam->curr_precision++;
		cur_dir += cam->FOV / cam->FOV_precision;
	}
	cur_dir = cam->FOV / 2 * -1;
		while (cur_dir < cam->FOV / 2)
	{
		cam->dir.x = data->player.dir.x * cos(cur_dir) - data->player.dir.y * sin(cur_dir);
		cam->dir.y = data->player.dir.x * sin(cur_dir) + data->player.dir.y * cos(cur_dir);
		ray_distance(data, cam->dir.x, cam->dir.y);
		draw_line_minimap(data, data->player.axis.x, data->player.axis.y,
						  data->player.axis.x + cam->dist * cam->dir.x,
						  data->player.axis.y + cam->dist * cam->dir.y);
		cam->curr_precision++;
		cur_dir += cam->FOV / cam->FOV_precision;
	}
}
