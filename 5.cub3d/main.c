/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:33:09 by namkyu            #+#    #+#             */
/*   Updated: 2021/03/30 22:02:00 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void texture_allocate(t_data *data)
{
	t_texture *tex;
	int width;
	int height;
	int sp_w;
	int sp_h;

	int a = 120;
	int b = 120;

	width = 64;
	height = 64;
	tex = &data->texture;
	tex->EA_img.ptr = mlx_xpm_file_to_image(data->system.mlx, data->texture.path[EA_ARR], &width, &height);
	tex->EA_img.data = (int *)mlx_get_data_addr(tex->EA_img.ptr, &tex->EA_img.bpp, &tex->EA_img.size_l, &tex->EA_img.endian);

	tex->WE_img.ptr = mlx_xpm_file_to_image(data->system.mlx, data->texture.path[WE_ARR], &width, &height);
	tex->WE_img.data = (int *)mlx_get_data_addr(tex->WE_img.ptr, &tex->WE_img.bpp, &tex->WE_img.size_l, &tex->WE_img.endian);

	tex->SO_img.ptr = mlx_xpm_file_to_image(data->system.mlx, data->texture.path[SO_ARR], &width, &height);
	tex->SO_img.data = (int *)mlx_get_data_addr(tex->SO_img.ptr, &tex->SO_img.bpp, &tex->SO_img.size_l, &tex->SO_img.endian);
	
	tex->NO_img.ptr = mlx_xpm_file_to_image(data->system.mlx, data->texture.path[NO_ARR], &width, &height);
	tex->NO_img.data = (int *)mlx_get_data_addr(tex->NO_img.ptr, &tex->NO_img.bpp, &tex->NO_img.size_l, &tex->NO_img.endian);

	tex->SP_img.ptr = mlx_xpm_file_to_image(data->system.mlx, data->texture.path[SP_ARR], &width, &height);
	tex->SP_img.data = (int *)mlx_get_data_addr(tex->SP_img.ptr, &tex->SP_img.bpp, &tex->SP_img.size_l, &tex->SP_img.endian);
}

void player_allocate(t_data *data)
{

	data->map.w_scale = 4;
	data->map.h_scale = 4;
	data->map.h_offset = data->resolution_height / data->map.h_scale * (data->map.h_scale - 1);

	data->map.cub_width = data->resolution_width / data->map.w_scale / data->map.col;
	data->map.cub_height = data->resolution_height / data->map.h_scale / data->map.row;

	data->player.mov_speed = 3;
	data->player.rot_speed = DEG_TO_RAD(25);
}

int key_press(int keycode, t_data *data)
{
	t_player *player;
	int x;
	int y;

	player = &data->player;
	if (keycode == KEY_W)
	{
		if (data->map.map_arr[(int)(player->axis.y)][(int)(player->axis.x + player->dir.x * player->mov_speed)] != '1')
			player->axis.x += player->dir.x * player->mov_speed;
		if (data->map.map_arr[(int)(player->axis.y + player->dir.y * player->mov_speed)][(int)(player->axis.x)] != '1')
			player->axis.y += player->dir.y * player->mov_speed;
	}
	else if (keycode == KEY_S)
	{
		if (data->map.map_arr[(int)(player->axis.y)][(int)(player->axis.x - player->dir.x * player->mov_speed)] != '1')
			player->axis.x -= player->dir.x * player->mov_speed;
		if (data->map.map_arr[(int)(player->axis.y - player->dir.y * player->mov_speed)][(int)(player->axis.x)] != '1')
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
	return (0);
}

int main_loop(t_data *data)
{
	if (data->crash_report)
		printf("!!!!!!!![%d]crash reported!!!!!!!\n", data->crash_report);
	ray_initalize(data);
	mlx_sync(MLX_SYNC_IMAGE_WRITABLE, data->img.ptr);
	mlx_put_image_to_window(data->system.mlx, data->system.win, data->img.ptr, 0, 0);
	mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, data->system.win);
	return (0);
}

int main()
{
	t_data data;
	data.crash_report = 0;

	cub_data_trim(&data);
	map_dfs(&data);

	data.system.mlx = mlx_init();
	data.system.win = mlx_new_window(data.system.mlx, data.resolution_width, data.resolution_height, "Namkyu's test");

	data.img.ptr = mlx_new_image(data.system.mlx, data.resolution_width, data.resolution_height);
	data.img.data = (int *)mlx_get_data_addr(data.img.ptr, &data.img.bpp, &data.img.size_l, &data.img.endian);

	texture_allocate(&data);
	player_allocate(&data);

	mlx_hook(data.system.win, X_EVENT_KEY_PRESS, 0, &key_press, &data);
	mlx_loop_hook(data.system.mlx, &main_loop, &data);
	mlx_loop(data.system.mlx);
}
