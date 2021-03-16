/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:33:13 by namkyu            #+#    #+#             */
/*   Updated: 2021/03/16 21:52:27 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "new_minilbx/mlx.h"
#include "3.GNL/get_next_line.h"
#include "1.libft/libft.h"

#define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_release	3
# define X_EVENT_KEY_EXIT		17

# define KEY_ESC		53
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# define CUB_DATA_CORRUPTED		5000

typedef struct s_img
{
	void		*ptr;
	int			*data;
	int			width;
	int			height;


	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct s_system
{
	void		*mlx;
	void		*win;
}				t_system;

typedef struct s_player
{
	double	y_axis;
	double	x_axis;
}				t_player;

typedef struct s_texture
{
	char	*NO_path;
	char	*SO_path;
	char	*WE_path;
	char	*EA_path;
	char	*Sprite_path;
	int		floor;
	int		ceiling;
}				t_texture;

typedef struct s_data
{
	t_system	system;
	t_img		img;
	t_player	player;
	t_texture	texture;
	char		**map;
	int			resolution_width;
	int			resolution_height;
	int			crash_report;
}				t_data;

void rgb_parse(char *str, int *object, t_data *data);
void resolution_parse(char *str, t_data *data);
void cub_data_sort(char *line, t_data *data);
void cub_data_trim(t_data *data);




void	map_parse();
int		key_press(int keycode, t_data *data);
void	player_allocate(t_player *palyer);

#endif