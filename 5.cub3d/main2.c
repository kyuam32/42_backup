/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:33:09 by namkyu            #+#    #+#             */
/*   Updated: 2021/03/09 21:27:08 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 //exit key code

//Mac key code example
//All the key code example other than below is described on the site linked in READEME.md

#include "cub3d.h"

void	player_allocate(t_player *palyer)
{
	palyer->x_axis = 30;
	palyer->y_axis = 30;
}

int		key_press(int keycode, t_player *player)
{
	static int a = 0;

	if (keycode == KEY_W)//Action when W key pressed
		player->y_axis++;
	else if (keycode == KEY_S) //Action when S key pressed
		player->y_axis--;
	else if (keycode == KEY_ESC) //Quit the program when ESC key pressed
		exit(0);
	printf("y: %f\n", player->y_axis);
	return (0);
}

int main()
{
	t_data	data;
	player_allocate(&data.player);
	data.system.mlx = mlx_init();
	data.system.win = mlx_new_window(data.system.mlx, 500, 500, "Namkyu's test");
	cub_data_trim(&data);
	mlx_hook(data.system.win, X_EVENT_KEY_PRESS, 0, &key_press, &data.player);
	mlx_loop(data.system.mlx);
}
