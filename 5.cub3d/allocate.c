/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:52:13 by namkyu            #+#    #+#             */
/*   Updated: 2021/04/09 15:20:50 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	allocate_system(t_data *data)
{
	data->system.mlx = mlx_init();
	data->system.win = mlx_new_window(data->system.mlx, \
			data->resolution_width, data->resolution_height, "Namkyu's Cub3d");
	data->img.ptr = mlx_new_image(data->system.mlx, \
			data->resolution_width, data->resolution_height);
	data->img.data = (int *)mlx_get_data_addr(data->img.ptr, \
				&data->img.bpp, &data->img.size_l, &data->img.endian);
}

void	allocate_texture(t_data *data)
{
	t_texture	*t;
	int			w;
	int			h;

	w = 64;
	h = 64;
	t = &data->texture;
	t->EA.ptr = mlx_xpm_file_to_image(data->system.mlx, t->path[EA_P], &w, &h);
	t->EA.data = (int *)mlx_get_data_addr(t->EA.ptr, \
									&t->EA.bpp, &t->EA.size_l, &t->EA.endian);
	t->WE.ptr = mlx_xpm_file_to_image(data->system.mlx, t->path[WE_P], &w, &h);
	t->WE.data = (int *)mlx_get_data_addr(t->WE.ptr, \
									&t->WE.bpp, &t->WE.size_l, &t->WE.endian);
	t->SO.ptr = mlx_xpm_file_to_image(data->system.mlx, t->path[SO_P], &w, &h);
	t->SO.data = (int *)mlx_get_data_addr(t->SO.ptr, \
									&t->SO.bpp, &t->SO.size_l, &t->SO.endian);
	t->NO.ptr = mlx_xpm_file_to_image(data->system.mlx, t->path[NO_P], &w, &h);
	t->NO.data = (int *)mlx_get_data_addr(t->NO.ptr, \
									&t->NO.bpp, &t->NO.size_l, &t->NO.endian);
	t->SP.ptr = mlx_xpm_file_to_image(data->system.mlx, t->path[SP_P], &w, &h);
	t->SP.data = (int *)mlx_get_data_addr(t->SP.ptr, \
									&t->SP.bpp, &t->SP.size_l, &t->SP.endian);
}

void	allocate_player(t_data *data)
{
	int scale;
	int	i;

	scale = 5;
	data->map.w_scale = scale;
	data->map.h_scale = scale;
	data->map.h_offset = data->resolution_height / scale * (scale - 1);
	data->map.cub_width = data->resolution_width / scale / data->map.col;
	data->map.cub_height = data->resolution_height / scale / data->map.row;
	data->player.mov_speed = 0.4;
	data->player.rot_speed = DEG_TO_RAD(10);
	i = -1;
	while (++i < 5)
		ft_free(data->texture.path[i]);
}
