/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:22:46 by namkyu            #+#    #+#             */
/*   Updated: 2021/04/08 21:21:01 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void map_allocate(t_data *data)
{
	t_minimap *map;
	int i;

	i = 0;
	map = &data->map;
	if (!(map->map_arr = (char **)malloc(sizeof(char *) * map->row + 1)))
		exit_process(data, MEM_ALLOCATE_FAILED + 1);
	while (i < map->row)
	{
		if (!(map->map_arr[i] = (char *)malloc(sizeof(char) * map->col + 1)))
			exit_process(data, MEM_ALLOCATE_FAILED + 1);
		map->map_arr[i][map->col] = 0;
		i++;
	}
	map->map_arr[i] = 0;
}

void map_str_to_array(t_data *data)
{
	int i;
	int j;
	char *map_str;

	i = 0;
	map_str = data->map.map_str;
	while (i < data->map.row)
	{
		j = 0;
		while (j < data->map.col)
		{
			if (*map_str == '.')
				while (j < data->map.col)
				{
					data->map.map_arr[i][j] = ' ';
					j++;
				}
			else
			{
				if (ft_strchr("EWSN", *map_str))
					player_dir_set(data, *map_str, i, j);
				else if (!(ft_strchr("012 ", *map_str)))
					exit_process(data, MAP_DATA_CORRUPTED + 2);
				data->map.map_arr[i][j] = *map_str;
				j++;
			}
			map_str++;
		}
		if (*map_str == '.')
			map_str++;
		i++;
	}
}

void map_sizecheck(t_data *data)
{
	int i;
	int row;
	int col;

	i = 0;
	col = 0;
	row = 0;
	while (data->map.map_str[i])
	{
		if (data->map.map_str[i] == '.')
		{
			row++;
			data->map.col = (data->map.col < col) ? col : data->map.col;
			col = 0;
		}
		else if (is_valid_char(data->map.map_str[i]))
			col++;
		else
			exit_process(data, MAP_DATA_CORRUPTED);
		i++;
	}
	data->map.row = row;
	if (data->map.col < 3 || data->map.row < 3)
		exit_process(data, MAP_DATA_CORRUPTED + 1);
}

void print_ptr(char **s)
{
	int i = -1;

	while (s[++i] != NULL)
		printf("map[%3d] = |%s|\n", i, s[i]);
}

void map_create(t_data *data)
{
	map_sizecheck(data);
	map_allocate(data);
	map_str_to_array(data);
	map_dfs(data);
	ft_free(data->map.map_str);

	printf("row : %d col : %d\n", data->map.row, data->map.col);
	print_ptr(data->map.map_arr);
}

void map_parse(char *line, t_data *data)
{
	char *map;
	char *temp;

	if (ft_strchr(line, '.'))
		exit_process(data, MAP_DATA_CORRUPTED + 5);
	if (!(map = ft_strjoin(data->map.map_str, line)))
		exit_process(data, MEM_ALLOCATE_FAILED);
	ft_free(data->map.map_str);
	temp = ft_strdup(map);
	ft_free(map);
	if (!(map = ft_strjoin(temp, ".")))
		exit_process(data, MEM_ALLOCATE_FAILED);
	ft_free(temp);
	data->map.map_str = map;
}
