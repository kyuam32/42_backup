/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:52:13 by namkyu            #+#    #+#             */
/*   Updated: 2021/04/07 20:58:07 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void allocate_system(t_data *data)
{
	data->system.mlx = mlx_init();
	data->system.win = mlx_new_window(data->system.mlx, data->resolution_width, data->resolution_height, "Namkyu's Cub3d");
	data->img.ptr = mlx_new_image(data->system.mlx, data->resolution_width, data->resolution_height);
	data->img.data = (int *)mlx_get_data_addr(data->img.ptr, &data->img.bpp, &data->img.size_l, &data->img.endian);
}
void allocate_texture(t_data *data)
{
	t_texture *tex;
	int width;
	int height;
	int i;

	width = 64;
	height = 64;
	tex = &data->texture;
	tex->EA_img.ptr = mlx_xpm_file_to_image(data->system.mlx, data->texture.path[EA], &width, &height);
	tex->EA_img.data = (int *)mlx_get_data_addr(tex->EA_img.ptr, &tex->EA_img.bpp, &tex->EA_img.size_l, &tex->EA_img.endian);
	tex->WE_img.ptr = mlx_xpm_file_to_image(data->system.mlx, data->texture.path[WE], &width, &height);
	tex->WE_img.data = (int *)mlx_get_data_addr(tex->WE_img.ptr, &tex->WE_img.bpp, &tex->WE_img.size_l, &tex->WE_img.endian);
	tex->SO_img.ptr = mlx_xpm_file_to_image(data->system.mlx, data->texture.path[SO], &width, &height);
	tex->SO_img.data = (int *)mlx_get_data_addr(tex->SO_img.ptr, &tex->SO_img.bpp, &tex->SO_img.size_l, &tex->SO_img.endian);
	tex->NO_img.ptr = mlx_xpm_file_to_image(data->system.mlx, data->texture.path[NO], &width, &height);
	tex->NO_img.data = (int *)mlx_get_data_addr(tex->NO_img.ptr, &tex->NO_img.bpp, &tex->NO_img.size_l, &tex->NO_img.endian);
	tex->SP_img.ptr = mlx_xpm_file_to_image(data->system.mlx, data->texture.path[SP], &width, &height);
	tex->SP_img.data = (int *)mlx_get_data_addr(tex->SP_img.ptr, &tex->SP_img.bpp, &tex->SP_img.size_l, &tex->SP_img.endian);
	i = -1;
	while (++i < 5)
		ft_free(data->texture.path[i]);
}

void allocate_player(t_data *data)
{
	data->map.w_scale = 4;
	data->map.h_scale = 4;
	data->map.h_offset = data->resolution_height / data->map.h_scale * (data->map.h_scale - 1);
	data->map.cub_width = data->resolution_width / data->map.w_scale / data->map.col;
	data->map.cub_height = data->resolution_height / data->map.h_scale / data->map.row;
	data->player.mov_speed = 0.5;
	data->player.rot_speed = DEG_TO_RAD(10);
}
