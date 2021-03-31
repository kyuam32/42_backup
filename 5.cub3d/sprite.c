/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 20:42:41 by namkyu            #+#    #+#             */
/*   Updated: 2021/03/31 22:15:44 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void sprite_ray_rad(t_data *data, int x, int y)
// {
// 	if (data->draw.sp_side == VIRTICAL_SIDE)
// 	{
// 		data->draw.sp_hit.x = x;
// 		data->draw.sp_hit.y = (data->player.axis.y + data->cam.sp_dist * data->cam.dir.y);
// 	}
// 	else
// 	{
// 		data->draw.sp_hit.x = (data->player.axis.x + data->cam.sp_dist * data->cam.dir.x);
// 		data->draw.sp_hit.y = y;
// 	}
// }

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
		rad1 = fabs(atan2(fabs(y + 1 - cur->y), fabs(x - cur->x)));
		rad2 = fabs(atan2(fabs(y - cur->y), fabs(x + 1 - cur->x)));
	}
	else if ((cur->x > x && cur->y < y) || (cur->x < x && cur->y > y))
	{
		rad1 = fabs(atan2(fabs(y - cur->y), fabs(x - cur->x)));
		rad2 = fabs(atan2(fabs(y + 1 - cur->y), fabs(x + 1 - cur->x)));
	}
	printf("%f\n", fabs(rad1 - rad2) * 180 / PI);
}
