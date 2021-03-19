/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:52:33 by namkyu            #+#    #+#             */
/*   Updated: 2021/03/19 18:22:12 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_graphic(t_data *data)
{
	double distance;
	int img_height;
	int height_mid;
	int ray_width;
	int ray_no;
	int i = 0;
	t_draw *draw = &data->draw;

	ray_no = data->cam.curr_precision;
	distance = (data->player.x_dir * data->cam.x_dir + data->player.y_dir * data->cam.y_dir) * data->cam.dist;

	if (distance < 1)
		img_height = (int)data->resolution_height / 2 / 2;
	else
		img_height = (int)(data->resolution_height / distance / 2 / 2);
	height_mid = (int)(data->resolution_height / 2 / 2);
	ray_width = (int)(data->resolution_width / data->cam.FOV_precision);
	while (i < ray_width)
	{
		draw->x_s = i + (ray_width * ray_no);
		draw->y_s = 0;
		draw->x_e = i + (ray_width * ray_no);
		draw->y_e = height_mid - img_height;
		draw->color = data->texture.ceiling;
		draw_line(data);
		draw->x_s = i + (ray_width * ray_no);
		draw->y_s = height_mid - img_height;
		draw->x_e = i + (ray_width * ray_no);
		draw->y_e = height_mid + img_height;
		draw->color = draw->side == HORIZOTAL_SIDE ? 0x006400 : 0x008000;
		draw_line(data);
		draw->x_s = i + (ray_width * ray_no);
		draw->y_s = height_mid + img_height;
		draw->x_e = i + (ray_width * ray_no);
		draw->y_e = height_mid + height_mid;
		draw->color = data->texture.floor;
		draw_line(data);
		i++;
	}
}
