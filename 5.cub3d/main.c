/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:33:09 by namkyu            #+#    #+#             */
/*   Updated: 2021/03/19 18:39:43 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void player_allocate(t_data *data)
{
	data->player.x_axis = 4.5;
	data->player.y_axis = 5.5;
	data->player.mov_speed = 0.3;
	data->player.rot_speed = PI / 30;
	data->player.x_dir = 0;
	data->player.y_dir = 1;
	data->mini_map.w_scale = 1/2;
	data->mini_map.h_scale = 1/2;
	data->mini_map.h_offset = data->resolution_height * (1 - data->mini_map.h_scale);
}

int key_press(int keycode, t_data *data)
{
	t_player *player;
	int x;
	int y;

	player = &data->player;
	if (keycode == KEY_W)
	{
		if (!(x = data->mini_map.map[(int)(player->y_axis)][(int)(player->x_axis + player->x_dir * player->mov_speed)]))
			player->x_axis += player->x_dir * player->mov_speed;
		if (!(y = data->mini_map.map[(int)(player->y_axis + player->y_dir * player->mov_speed)][(int)(player->x_axis)]))
			player->y_axis += player->y_dir * player->mov_speed;
	}
	else if (keycode == KEY_S)
	{
		if (!(x = data->mini_map.map[(int)(player->y_axis)][(int)(player->x_axis - player->x_dir * player->mov_speed)]))
			player->x_axis -= player->x_dir * player->mov_speed;
		if (!(y = data->mini_map.map[(int)(player->y_axis - player->y_dir * player->mov_speed)][(int)(player->x_axis)]))
			player->y_axis -= player->y_dir * player->mov_speed;
	}
	else if (keycode == KEY_D)
	{
		double x_olddir = player->x_dir;
		double y_olddir = player->y_dir;
		player->x_dir = x_olddir * cos(player->rot_speed) - y_olddir * sin(player->rot_speed);
		player->y_dir = x_olddir * sin(player->rot_speed) + y_olddir * cos(player->rot_speed);
	}
	else if (keycode == KEY_A)
	{
		double x_olddir = player->x_dir;
		double y_olddir = player->y_dir;
		player->x_dir = x_olddir * cos(-player->rot_speed) - y_olddir * sin(-player->rot_speed);
		player->y_dir = x_olddir * sin(-player->rot_speed) + y_olddir * cos(-player->rot_speed);
	}
	else if (keycode == KEY_ESC)
		exit(0);
	// printf("x = [%f] y = [%f]\ndir_x = [%f] dir_y =[%f]\n ", player->x_axis, player->y_axis, player->x_dir, player->y_dir);
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
	memcpy(data->mini_map.map, map, sizeof(int) * 11 * 15);
}

int main_loop(t_data *data)
{
	m_map_wall(data);
	m_map_grid(data);
	m_map_player(data);
	ray_casting(data);
	mlx_put_image_to_window(data->system.mlx, data->system.win, data->img.ptr, 0, 0);
	return (0);
}

int main()
{
	t_data data;

	data.system.mlx = mlx_init();

	cub_data_trim(&data);
	temp_map(&data);

	data.mini_map.row = 11;
	data.mini_map.col = 15;
	data.mini_map.width = data.resolution_width / 2;
	data.mini_map.height = data.resolution_height / 2;
	data.mini_map.cub_width = data.mini_map.width / data.mini_map.col;
	data.mini_map.cub_height = data.mini_map.height / data.mini_map.row;

	data.system.win = mlx_new_window(data.system.mlx, data.resolution_width, data.resolution_height, "Namkyu's test");

	data.img.ptr = mlx_new_image(data.system.mlx, data.resolution_width, data.resolution_height);
	data.img.data = (int *)mlx_get_data_addr(data.img.ptr, &data.img.bpp, &data.img.size_l, &data.img.endian);

	player_allocate(&data);
	// main_loop(&data);

	mlx_hook(data.system.win, X_EVENT_KEY_PRESS, 0, &key_press, &data);
	mlx_loop_hook(data.system.mlx, &main_loop, &data);
	mlx_loop(data.system.mlx);
}

// mlx_sync()
