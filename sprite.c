/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 20:42:41 by namkyu            #+#    #+#             */
/*   Updated: 2021/03/31 21:12:05 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"

// void sprite_ray_rad(t_data *data, int x, int y)
// {
// 	t_vector hit;

// 	if (data->sprite.side == VIRTICAL_SIDE)
// 	{
// 		hit.x = x;
// 		hit.y = (data->player.axis.y + data->cam.dist * data->cam.dir.y);
// 	}
// 	else
// 	{
// 		hit.x = (data->player.axis.x + data->cam.dist * data->cam.dir.x);
// 		hit.y = y;
// 	}
// 	printf("%f /// %f\n", hit.x, hit.y);
// }

// void sprite_rad(t_data *data, int x, int y)
// {
// 	double rad1;
// 	double rad2;
// 	t_vector *cur;

// 	cur = &data->player.axis;
// 	if (x <= cur->x  && cur->x <= x + 1)
// 	{
// 		if (cur->y > y)
// 			y += 1;
// 		rad1 = fabs(PI - atan2(fabs(y - cur->y), fabs(x - cur->x)));
// 		rad2 = fabs(atan2(fabs(y - cur->y), fabs(x + 1 - cur->x)));
// 	}
// 	else if (y <= cur->y && cur->y <= y + 1)
// 	{
// 		if (cur->x > x)
// 			x += 1;
// 		rad1 = fabs(atan2(fabs(y - cur->y), fabs(x - cur->x)));
// 		rad2 = fabs(atan2(fabs(y + 1 - cur->y), fabs(x - cur->x))) * -1;
// 	}
// 	else if ((cur->x < x && cur->y < y) || (cur->x > x && cur->y > y))
// 	{
// 		rad1 = fabs(atan2(fabs(y + 1 - cur->y), fabs(x - cur->x)));
// 		rad2 = fabs(atan2(fabs(y - cur->y), fabs(x + 1 - cur->x)));
// 	}
// 	else if ((cur->x > x && cur->y < y) || (cur->x < x && cur->y > y))
// 	{
// 		rad1 = fabs(atan2(fabs(y - cur->y), fabs(x - cur->x)));
// 		rad2 = fabs(atan2(fabs(y + 1 - cur->y), fabs(x + 1 - cur->x)));
// 	}
// 	data->sprite.sp_rad = fabs(rad1 - rad2);
// }
