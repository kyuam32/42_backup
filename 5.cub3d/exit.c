/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:13:18 by namkyu            #+#    #+#             */
/*   Updated: 2021/04/09 15:09:09 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int exit_win(t_data *data)
{
	exit_process(data, 0);
	return(0);
}

void exit_message(t_data *data)
{
	if (data->crash_report)
	{
		printf("\n!!! ERROR NO [%d] !!!\n", data->crash_report);
		{
		if (data->crash_report >= 5000)
			printf("--- CUB_DATA_CORRUPTED ---\n");
		else if (data->crash_report >= 4000)
			printf("--- MAP_DATA_CORRUPTED ---\n");
		else if (data->crash_report >= 3000)
			printf("--- MEMORY_ALLOCATE_FAILED ---\n");
		else if (data->crash_report >= 2000)
			printf("--- CANT_OPEN_FILE ---\n");
		else if (data->crash_report >= 1000)
			printf("--- ARGUMENT_ERR ---\n");
		}
		printf("!!! ERROR NO [%d] !!!\n\n", data->crash_report);
	}
}

void exit_mlx_destroy(t_data *data)
{
	if (data->texture.EA.ptr)
		mlx_destroy_image(data->system.mlx, data->texture.EA.ptr);
	if (data->texture.WE.ptr)
		mlx_destroy_image(data->system.mlx, data->texture.WE.ptr);
	if (data->texture.SO.ptr)
		mlx_destroy_image(data->system.mlx, data->texture.SO.ptr);
	if (data->texture.NO.ptr)
		mlx_destroy_image(data->system.mlx, data->texture.NO.ptr);
	if (data->texture.SP.ptr)
		mlx_destroy_image(data->system.mlx, data->texture.SP.ptr);
	if (data->img.ptr)
		mlx_destroy_image(data->system.mlx, data->img.ptr);
	if (data->system.win)
		mlx_destroy_window(data->system.mlx, data->system.win);

}

void exit_process(t_data *data, int errno)
{
	data->crash_report = errno;
	exit_message(data);
	exit_mlx_destroy(data);
	exit(data->crash_report);
}