/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:33:09 by namkyu            #+#    #+#             */
/*   Updated: 2021/03/16 21:56:50 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_allocate(t_player *palyer)
{
	palyer->x_axis = 30;
	palyer->y_axis = 30;
}

int		key_press(int keycode, t_data *data)
{
	t_player *player;

	player = &data->player;

	if (keycode == KEY_W)//Action when W key pressed
	{
		player->y_axis++;
		data->texture.ceiling += 1000; 
		data->texture.floor += 1000; 
	}
	else if (keycode == KEY_S) //Action when S key pressed
		player->y_axis--;
	else if (keycode == KEY_ESC) //Quit the program when ESC key pressed
		exit(0);
	printf("y: %f\n", player->y_axis);
	return (0);
}


int draw_window(t_data *data)
{
	t_img *img = &data->img;
	int count_h;
	int count_w;

	img->ptr = mlx_new_image(data->system.mlx, data->resolution_width, data->resolution_height);
	img->data = (int *)mlx_get_data_addr(img->ptr, &img->bpp, &img->size_l, &img->endian);

	count_h = -1;
	while (++count_h < data->resolution_height)
	{
		count_w = -1;
		while (++count_w < data->resolution_width)
		{
			if (count_w % 50)
				img->data[count_h * img->size_l / 4 + count_w] = data->texture.ceiling;
			// else if (count_h % 200)
			// 	img->data[count_h * img->size_l / 4 + count_w] = data->texture.ceiling;
			else
				img->data[count_h * img->size_l / 4 + count_w] = data->texture.floor;
		}
	}
	return (0);
}

int main_loop(t_data *data)
{
	draw_window(data);
	// draw_palyer(data);
	mlx_put_image_to_window(data->system.mlx, data->system.win, data->img.ptr, 0, 0);
	return (0);
}

int main()
{
	t_data	data;

	player_allocate(&data.player);
	data.system.mlx = mlx_init();
	
	cub_data_trim(&data);

	data.system.win = mlx_new_window(data.system.mlx, data.resolution_width, data.resolution_height, "Namkyu's test");

	// mlx_sync()

	mlx_hook(data.system.win, X_EVENT_KEY_PRESS, 0, &key_press, &data);
	mlx_loop_hook(data.system.mlx, &main_loop, &data);
	mlx_loop(data.system.mlx);
}
