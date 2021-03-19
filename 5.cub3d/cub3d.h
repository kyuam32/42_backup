/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:33:13 by namkyu            #+#    #+#             */
/*   Updated: 2021/03/19 18:22:10 by namkyu           ###   ########.fr       */
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

#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_release 3
#define X_EVENT_KEY_EXIT 17

#define KEY_ESC 53
#define KEY_Q 12
#define KEY_W 13
#define KEY_E 14
#define KEY_R 15
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

#define CUB_DATA_CORRUPTED 5000

#define HORIZOTAL_SIDE 0
#define VIRTICAL_SIDE 1
#define MIN(a, b) ((a < b) ? a : b)
#define MAX(a, b) ((a < b) ? b : a)
#define PI 3.14159265359
#define DEG_TO_RAD(x) (x * PI / 180)

typedef struct s_img
{
	void *ptr;
	int *data;
	int width;
	int height;

	int size_l;
	int bpp;
	int endian;
} t_img;

typedef struct s_system
{
	void *mlx;
	void *win;
} t_system;

typedef struct s_player
{
	double y_axis;
	double x_axis;
	double y_dir;
	double x_dir;
	double y_plane;
	double x_plane;
	double mov_speed;
	double rot_speed;
} t_player;

typedef struct s_texture
{
	char *NO_path;
	char *SO_path;
	char *WE_path;
	char *EA_path;
	char *Sprite_path;
	int floor;
	int ceiling;
} t_texture;

typedef struct s_minimap
{
	int map[11][15];
	int cub_width;
	int cub_height;
	int row;
	int col;
	int width;
	int height;
	int w_scale;
	int h_scale;
	int h_offset;

} t_minimap;

typedef struct s_draw
{
	int x_s;
	int x_e;
	int y_s;
	int y_e;
	int color;
	int tile;
	int side;
} t_draw;

typedef struct s_cam
{
	double FOV;
	int FOV_precision;
	int curr_precision;
	double x_dir;
	double y_dir;
	double dist;
} t_cam;

typedef struct s_data
{
	t_system system;
	t_img img;
	t_player player;
	t_texture texture;
	t_minimap mini_map;
	t_cam cam;
	t_draw draw;
	int cub_size;
	int resolution_width;
	int resolution_height;
	int crash_report;
} t_data;

/*
// DATA PARSE
*/

void rgb_parse(char *str, int *object, t_data *data);
void resolution_parse(char *str, t_data *data);
void cub_data_sort(char *line, t_data *data);
void cub_data_trim(t_data *data);
void texture_path_parse(char *str, char *path, t_data *data);

/*
// BASIC DRAWING TOOL (LINE)
*/
void drawVLine(t_data *data, int y_start, int y_end, int x_start);
void drawHLine(t_data *data, int x_start, int x_end, int y_start);
void draw_line(t_data *data);

/*
// RAYCAST
*/

double line_distance(t_data *data, double x_dir, double y_dir);
void ray_casting(t_data *data);

/*
// CREATE MINI_MAP
*/

void m_map_grid(t_data *data);
void draw_line_minimap(t_data *data, double x_start, double y_start, double x_end, double y_end);
void draw_rectangle(t_data *data, int x, int y, int color);
void m_map_wall(t_data *data);
void m_map_player(t_data *data);

/*
// DISPLAY
*/

void draw_graphic(t_data *data);

/*
// MAIN
*/

void player_allocate(t_data *data);
int key_press(int keycode, t_data *data);
void map_parse();
void temp_map(t_data *data);
int main_loop(t_data *data);

#endif