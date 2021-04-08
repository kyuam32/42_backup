/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:33:09 by namkyu            #+#    #+#             */
/*   Updated: 2021/04/08 20:14:56 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_press(int keycode, t_data *data)
{
	t_player *player;
	t_vector dir;
	int inv;

	player = &data->player;
	inv = 1;
	if (keycode == KEY_S || keycode == KEY_A || keycode == KEY_LEFT)
		inv *= -1;
	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A || keycode == KEY_D)
	{
		if (keycode == KEY_W || keycode == KEY_S)
		{
			dir.x = player->dir.x * inv;
			dir.y = player->dir.y * inv;
		}
		else if (keycode == KEY_A || keycode == KEY_D)
		{
			dir.x = player->dir.y * -1 * inv;
			dir.y = player->dir.x * inv;
		}
		if (data->map.map_arr[(int)(player->axis.y)][(int)(player->axis.x + dir.x * player->mov_speed)] != '1')
			player->axis.x += dir.x * player->mov_speed;
		if (data->map.map_arr[(int)(player->axis.y + dir.y * player->mov_speed)][(int)(player->axis.x)] != '1')
			player->axis.y += dir.y * player->mov_speed;
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_LEFT)
	{
		dir.x = player->dir.x;
		dir.y = player->dir.y;
		player->dir.x = dir.x * cos(player->rot_speed * inv) - dir.y * sin(player->rot_speed * inv);
		player->dir.y = dir.x * sin(player->rot_speed * inv) + dir.y * cos(player->rot_speed * inv);
	}
	else if (keycode == KEY_ESC)
		exit_process(data, 0);
	return (0);
}

int main_loop(t_data *data)
{
	ray_initalize(data);
	mlx_sync(MLX_SYNC_IMAGE_WRITABLE, data->img.ptr);
	mlx_put_image_to_window(data->system.mlx, data->system.win, data->img.ptr, 0, 0);
	mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, data->system.win);

	return (0);
}

void input_check(t_data *data, int argc, char **argv)
{
	if (argc == 2 || argc == 3)
	{
		data->cub_path = ft_strdup(argv[1]);
		if (argc == 3)
		{
			if (ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) == 0)
				data->bit_map = 1;
			else
				exit_process(data, ARGUMENT_ERROR + 1);
		}
	}
	else
		exit_process(data, ARGUMENT_ERROR);
}

int main(int argc, char **argv)
{
	t_data data;

	ft_memset(&data, 0, sizeof(t_data));
	input_check(&data, argc, argv);
	cub_data_trim(&data);
	map_create(&data);
	allocate_system(&data);
	allocate_texture(&data);
	allocate_player(&data);
	if (data.bit_map)
	{
		ray_initalize(&data);
		bitmap_create(&data);
	}
	mlx_hook(data.system.win, X_EVENT_KEY_PRESS, 0, &key_press, &data);
	mlx_hook(data.system.win, X_EVENT_EXIT, 0, &exit_win, &data);
	mlx_loop_hook(data.system.mlx, &main_loop, &data);
	mlx_loop(data.system.mlx);
}
