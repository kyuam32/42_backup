/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:33:13 by namkyu            #+#    #+#             */
/*   Updated: 2021/04/08 21:20:34 by namkyu           ###   ########.fr       */
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
#define X_EVENT_EXIT 17

#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_RIGHT 124
#define KEY_LEFT 123

#define CUB_DATA_CORRUPTED 5000
#define MAP_DATA_CORRUPTED 4000
#define MEM_ALLOCATE_FAILED 3000
#define CANT_OPEN_FILE 2000
#define ARGUMENT_ERROR 1000

#define HORIZOTAL_SIDE 0
#define VIRTICAL_SIDE 1
#define MIN(a, b) ((a < b) ? a : b)
#define MAX(a, b) ((a < b) ? b : a)
#define PI 3.14159265359
#define DEG_TO_RAD(x) (x * PI / 180)

#define EA 0
#define WE 1
#define SO 2
#define NO 3
#define SP 4

#pragma pack(push, 1) // 구조체를 1바이트 크기로 정렬

typedef struct s_bmheader // BMP 비트맵 파일 헤더 구조체
{
	unsigned char Type1;	   // BMP 파일 매직 넘버
	unsigned char Type2;	   // BMP 파일 매직 넘버
	unsigned int fSize;		   // 파일 크기
	unsigned short Reserved1;  // 예약
	unsigned short Reserved2;  // 예약
	unsigned int OffBits;	   // 비트맵 데이터의 시작 위치
	unsigned int iSize;		   // 현재 구조체의 크기
	int Width;				   // 비트맵 이미지의 가로 크기
	int Height;				   // 비트맵 이미지의 세로 크기
	unsigned short Planes;	   // 사용하는 색상판의 수
	unsigned short BitCount;   // 픽셀 하나를 표현하는 비트 수
	unsigned int Compression;  // 압축 방식
	unsigned int SizeImage;	   // 비트맵 이미지의 픽셀 데이터 크기
	int XPelsPerMeter;		   // 그림의 가로 해상도(미터당 픽셀)
	int YPelsPerMeter;		   // 그림의 세로 해상도(미터당 픽셀)
	unsigned int ClrUsed;	   // 색상 테이블에서 실제 사용되는 색상 수
	unsigned int ClrImportant; // 비트맵을 표현하기 위해 필요한 색상 인덱스 수
} t_bmheader;

#pragma pack(pop)

typedef struct s_vector
{
	double x;
	double y;
} t_vector;

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
	t_vector axis;
	t_vector dir;
	double mov_speed;
	double rot_speed;
	int locate;
} t_player;

typedef struct s_texture
{
	char *path[5];
	t_img NO_img;
	t_img SO_img;
	t_img WE_img;
	t_img EA_img;
	t_img SP_img;
	int floor;
	int ceiling;
} t_texture;

typedef struct s_minimap
{
	char **map_arr;
	char *map_str;
	int cub_width;
	int cub_height;
	int row;
	int col;
	int w_scale;
	int h_scale;
	int h_offset;
	char **dfs;
} t_minimap;

typedef struct s_draw
{
	t_vector start;
	t_vector end;
	int color;
	int tile;
	int side;
} t_draw;

typedef struct s_cam
{
	t_vector dir;
	double FOV;
	int FOV_precision;
	int curr_precision;
	double dist;
} t_cam;

typedef struct s_sprite
{
	t_vector hit;
	double sp_rad;
	double sp_dist;
	double sp_adj_dist;
	int sp_side;
} t_sprite;

typedef struct s_data
{
	t_system system;
	t_img img;
	t_player player;
	t_texture texture;
	t_minimap map;
	t_cam cam;
	t_draw draw;
	t_sprite sprite;
	char *cub_path;
	int cub_size;
	int resolution_width;
	int resolution_height;
	int crash_report;
	int bit_map;
} t_data;

/*
// DATA PARSE
*/

void rgb_parse(char *str, int *object, t_data *data);
void resolution_parse(char *str, t_data *data);
void cub_data_sort(char *line, t_data *data);
void cub_data_trim(t_data *data);
void texture_path_parse(char *str, int type, t_data *data);
/*
// BASIC DRAWING TOOL (LINE)
*/

void draw_line(t_data *data);
void draw_ray(t_data *data);
void draw_3d(t_data *data);
void draw_rectangle(t_data *data, int x, int y, int color);
void draw_texture(t_data *data, int x, int y, int height);
void draw_sp(t_data *data);

/*
// RAYCAST
*/

void ray_cast(t_data *data, void (*draw_target)(t_data *));
// void ray_distance(t_data *data, double x_dir, double y_dir);
void ray_distance(t_data *data, t_vector *dir);
void ray_initalize(t_data *data);
void ray_sprite(t_data *data, double x_dir, double y_dir);

void sprite_rad(t_data *data, int x, int y);
void sprite_ray_rad(t_data *data, int x, int y);

/*
// CREATE MINI_MAP
*/

void m_map_grid(t_data *data);
void m_map_wall(t_data *data);
void m_map_player(t_data *data);

/*
// CREATE MAP_STR
*/
void map_parse(char *line, t_data *data);
void map_create(t_data *data);
void map_allocate(t_data *data);
void map_sizecheck(t_data *data);
void map_dfs_free(t_data *data);

/*
// EXIT
*/
int exit_win(t_data *data);
void exit_message(t_data *data);
void exit_mlx_destroy(t_data *data);
void exit_process(t_data *data, int errno);

/*
// DFS MAP VALID CHECK
*/
void map_dfs(t_data *data);
int map_search_escape(t_data *data, char **is_visited, int x, int y);

/*
// BITMAP
*/
void bitmap_header(t_bmheader *header, int width, int height);
void bitmap_create(t_data *data);
/*
// UTILS
*/

void v_put(t_vector *vec, int x_input, int y_input);
int is_valid_char(char c);
void player_dir_set(t_data *data, char c, int row, int col);
void error_stop(t_data *data, int errno);
void error_message(t_data *data);
void ft_free(void *target);
void exit_process(t_data *data, int errno);

void print_ptr(char **s);

/*
// MAIN
*/

void allocate_player(t_data *data);
void allocate_texture(t_data *data);
void allocate_system(t_data *data);
int key_press(int keycode, t_data *data);
void map_parse();
void temp_map(t_data *data);
int main_loop(t_data *data);

#endif