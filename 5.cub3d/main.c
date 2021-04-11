/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:33:09 by namkyu            #+#    #+#             */
/*   Updated: 2021/04/10 19:18:51 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main_loop(t_data *data)
{
	ray_initalize(data);
	mlx_sync(MLX_SYNC_IMAGE_WRITABLE, data->img.ptr);
	mlx_put_image_to_window(data->system.mlx, \
						data->system.win, data->img.ptr, 0, 0);
	mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, data->system.win);
	return (0);
}

void	input_check(t_data *data, int argc, char **argv)
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

int		main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	input_check(&data, argc, argv);
	parse_cub_data(&data);
	map_create(&data);
	allocate_system(&data);
	allocate_texture(&data);
	allocate_player(&data);
	if (data.bit_map)
	{
		ray_initalize(&data);
		bitmap_create(&data);
		exit_process(&data, 0);
	}
	mlx_hook(data.system.win, X_EVENT_KEY_PRESS, 0, &key_press, &data);
	mlx_hook(data.system.win, X_EVENT_EXIT, 0, &exit_win, &data);
	mlx_loop_hook(data.system.mlx, &main_loop, &data);
	mlx_loop(data.system.mlx);
}
