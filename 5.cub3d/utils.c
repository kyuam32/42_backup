/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:54:33 by namkyu            #+#    #+#             */
/*   Updated: 2021/04/06 21:38:55 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void error_message(t_data *data)
{
	printf("!!! ERROR NO [%d] !!!\n", data->crash_report);
	if (data->crash_report >= 5000)
		printf("CUB_DATA_CORRUPTED\n");
	else if (data->crash_report >= 4000)
		printf("MAP_DATA_CORRUPTED\n");
	else if (data->crash_report >= 3000)
		printf("MEM_ALLOCATE_FAILED\n");
}

void error_img_destroy(t_data *data)
{
	if (data->texture.EA_img.ptr)
		mlx_destroy_image(data->system.mlx, data->texture.EA_img.ptr);
	if (data->texture.WE_img.ptr)
		mlx_destroy_image(data->system.mlx, data->texture.WE_img.ptr);
	if (data->texture.SO_img.ptr)
		mlx_destroy_image(data->system.mlx, data->texture.SO_img.ptr);
	if (data->texture.NO_img.ptr)
		mlx_destroy_image(data->system.mlx, data->texture.NO_img.ptr);
	if (data->texture.SP_img.ptr)
		mlx_destroy_image(data->system.mlx, data->texture.SP_img.ptr);
	if (data->img.ptr)
		mlx_destroy_image(data->system.mlx, data->img.ptr);
}

void error_stop(t_data *data, int errno)
{
	int i;

	data->crash_report = errno;
	if (data->map.map_str)
		free(data->map.map_str);
	if (data->map.map_arr)
	{
		i = 0;
		while (i < data->map.row)
		{
			if (data->map.map_arr[i])
				free(data->map.map_arr[i]);
			i++;
		}
		free(data->map.map_arr);
	}
	map_dfs_free(data);
	error_message(data);
	error_img_destroy(data);
	if (data->system.win)
		mlx_destroy_window(data->system.mlx, data->system.win);
}

void v_put(t_vector *vec, int x_input, int y_input)
{
	vec->x = (double)x_input;
	vec->y = (double)y_input;
}

int is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == 'E' || c == 'W' || c == 'S' || c == 'N' || c == ' ')
		return (1);
	return (0);
}

void player_dir_set(t_data *data, char c, int row, int col)
{
	if (data->player.locate == 0)
	{
		data->player.locate = c;
		if (c == 'E')
		{
			data->player.dir.x = 1;
			data->player.dir.y = 0;
		}
		else if (c == 'W')
		{
			data->player.dir.x = -1;
			data->player.dir.y = 0;
		}
		else if (c == 'S')
		{
			data->player.dir.x = 0;
			data->player.dir.y = 1;
		}
		else if (c == 'N')
		{
			data->player.dir.x = 0;
			data->player.dir.y = -1;
		}
		data->player.axis.x = col + 0.5;
		data->player.axis.y = row + 0.5;
	}
	else
		data->crash_report = MAP_DATA_CORRUPTED + 3;
}