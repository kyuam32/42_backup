/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 20:42:41 by namkyu            #+#    #+#             */
/*   Updated: 2021/04/07 14:12:51 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void sprite_ray_rad(t_data *data, int x, int y)
{
	t_vector *cur;
	t_vector *hit;
	double rad1;
	double rad2;

	cur = &data->player.axis;
	hit = &data->sprite.hit;
	hit->x = (cur->x > x) ? x + 1 : x;
	hit->y = (cur->y > y) ? y + 1 : y;
	if (data->sprite.sp_side == VIRTICAL_SIDE)
		hit->y = (data->player.axis.y + (data->sprite.sp_dist * data->cam.dir.y));
	else
		hit->x = (data->player.axis.x + (data->sprite.sp_dist * data->cam.dir.x));
	rad1 = (atan2((hit->y - cur->y), (hit->x - cur->x)));
	if ((cur->x <= x + 1 && cur->y <= y))
		rad2 = (atan2((y - cur->y), (x + 1 - cur->x)));
	else if ((cur->x > x + 1 && cur->y <= y + 1)) ////////////////////////
	{
		if (rad1 < 0)
			rad1 = PI + PI + rad1;
		rad2 = (atan2((y + 1 - cur->y), (x + 1 - cur->x)));
	}
	else if ((cur->x >= x && cur->y >= y + 1))
		rad2 = (atan2((y + 1 - cur->y), (x - cur->x)));
	else if ((cur->x < x && cur->y > y))
		rad2 = (atan2((y - cur->y), (x - cur->x)));
	data->sprite.sp_rad = fabs(rad1 - rad2) / data->sprite.sp_rad;
}

void sprite_rad(t_data *data, int x, int y)
{
	t_vector *cur;
	double rad1;
	double rad2;

	cur = &data->player.axis;
	if (x <= cur->x  && cur->x <= x + 1)
	{
		if (cur->y > y)
			y += 1;
		rad1 = fabs(PI - atan2(fabs(y - cur->y), fabs(x - cur->x)));
		rad2 = fabs(atan2(fabs(y - cur->y), fabs(x + 1 - cur->x)));
	}
	else if (y <= cur->y && cur->y <= y + 1)
	{
		if (cur->x > x)
			x += 1;
		rad1 = fabs(atan2(fabs(y - cur->y), fabs(x - cur->x)));
		rad2 = fabs(atan2(fabs(y + 1 - cur->y), fabs(x - cur->x))) * -1;
	}
	else if ((cur->x < x && cur->y < y) || (cur->x > x && cur->y > y))
	{
		rad1 = (atan2((y + 1 - cur->y), (x - cur->x)));
		rad2 = (atan2((y - cur->y), (x + 1 - cur->x)));
	}
	else if ((cur->x > x && cur->y < y) || (cur->x < x && cur->y > y))
	{
		rad1 = (atan2((y - cur->y), (x - cur->x)));
		rad2 = (atan2((y + 1 - cur->y), (x + 1 - cur->x)));
	}
	data->sprite.sp_rad = fabs(rad1 - rad2);
}
