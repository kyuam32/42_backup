/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:33:09 by namkyu            #+#    #+#             */
/*   Updated: 2021/03/22 16:20:35 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void player_allocate(t_data *data)
{

	data->map.row = 11;
	data->map.col = 15;

	data->map.w_scale = 4;
	data->map.h_scale = 4;
	data->map.h_offset = data->resolution_height / data->map.h_scale * (data->map.h_scale - 1);

	data->map.cub_width = data->resolution_width / data->map.w_scale / data->map.col;
	data->map.cub_height = data->resolution_height / data->map.h_scale / data->map.row;

	data->player.axis.x = 4.5;
	data->player.axis.y = 5.5;
	data->player.mov_speed = 0.3;
	data->player.rot_speed = PI / 30;
	data->player.dir.x = 0;
	data->player.dir.y = 1;

}

int key_press(int keycode, t_data *data)
{
	t_player *player;
	int x;
	int y;

	player = &data->player;
	if (keycode == KEY_W)
	{
		if (!(x = data->map.map[(int)(player->axis.y)][(int)(player->axis.x + player->dir.x * player->mov_speed)]))
			player->axis.x += player->dir.x * player->mov_speed;
		if (!(y = data->map.map[(int)(player->axis.y + player->dir.y * player->mov_speed)][(int)(player->axis.x)]))
			player->axis.y += player->dir.y * player->mov_speed;
	}
	else if (keycode == KEY_S)
	{
		if (!(x = data->map.map[(int)(player->axis.y)][(int)(player->axis.x - player->dir.x * player->mov_speed)]))
			player->axis.x -= player->dir.x * player->mov_speed;
		if (!(y = data->map.map[(int)(player->axis.y - player->dir.y * player->mov_speed)][(int)(player->axis.x)]))
			player->axis.y -= player->dir.y * player->mov_speed;
	}
	else if (keycode == KEY_D)
	{
		double x_olddir = player->dir.x;
		double y_olddir = player->dir.y;
		player->dir.x = x_olddir * cos(player->rot_speed) - y_olddir * sin(player->rot_speed);
		player->dir.y = x_olddir * sin(player->rot_speed) + y_olddir * cos(player->rot_speed);
	}
	else if (keycode == KEY_A)
	{
		double x_olddir = player->dir.x;
		double y_olddir = player->dir.y;
		player->dir.x = x_olddir * cos(-player->rot_speed) - y_olddir * sin(-player->rot_speed);
		player->dir.y = x_olddir * sin(-player->rot_speed) + y_olddir * cos(-player->rot_speed);
	}
	else if (keycode == KEY_ESC)
		exit(0);
	// printf("x = [%f] y = [%f]\ndir_x = [%f] dir_y =[%f]\n ", player->axis.x, player->axis.y, player->dir.x, player->dir.y);
	return (0);
}

void temp_map(t_data *data)
{
	int map[11][15] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
	memcpy(data->map.map, map, sizeof(int) * 11 * 15);
}

int main_loop(t_data *data)
{

	ray_casting(data);

	mlx_put_image_to_window(data->system.mlx, data->system.win, data->img.ptr, 0, 0);
	return (0);
}

int main()
{
	t_data data;

	cub_data_trim(&data);
	temp_map(&data);

	data.system.mlx = mlx_init();
	data.system.win = mlx_new_window(data.system.mlx, data.resolution_width, data.resolution_height, "Namkyu's test");

	data.img.ptr = mlx_new_image(data.system.mlx, data.resolution_width, data.resolution_height);
	data.img.data = (int *)mlx_get_data_addr(data.img.ptr, &data.img.bpp, &data.img.size_l, &data.img.endian);

	player_allocate(&data);

	printf("%d  :  %d\n", data.map.w_scale, data.map.h_scale);
	mlx_hook(data.system.win, X_EVENT_KEY_PRESS, 0, &key_press, &data);
	mlx_loop_hook(data.system.mlx, &main_loop, &data);
	mlx_loop(data.system.mlx);
}

// mlx_sync()
