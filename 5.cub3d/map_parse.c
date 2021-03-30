/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:22:46 by namkyu            #+#    #+#             */
/*   Updated: 2021/03/26 19:59:23 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void map_allocate(t_data *data)
{
	t_minimap *map;
	int i;

	i = 0;
	map = &data->map;

	map->map_arr = (char **)malloc(sizeof(char *) * map->row + 1);
	while (i < map->row)
	{
		map->map_arr[i] = (char *)malloc(sizeof(char) * map->col + 1);
		map->map_arr[i][map->col] = 0;
		i++;
	}
	map->map_arr[i] = NULL;
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
			if (*map_str == '\n' || *map_str == 0)
			{
				while (j < data->map.col)
				{
					data->map.map_arr[i][j] = ' ';
					j++;
				}
			}
			else
			{
				if (*map_str == 'E' || *map_str == 'W' || *map_str == 'S' || *map_str == 'N')
				{
					data->map.map_arr[i][j] = *map_str;
					player_dir_set(data ,*map_str, i, j);
				}
				else
					data->map.map_arr[i][j] = *map_str;
				j++;
			}
			map_str++;
		}
		if (*map_str == '\n')
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
		if (data->map.map_str[i] == '\n')
		{
			row++;
			data->map.col = (data->map.col < col) ? col : data->map.col;
			col = 0;
		}
		else if (is_valid_char(data->map.map_str[i]))
			col++;
		else
			data->crash_report = MAP_DATA_CORRUPTED + 1;
		i++;
	}
	data->map.row = row;
	if (data->map.col < 3 || data->map.row < 3)
		data->crash_report = MAP_DATA_CORRUPTED + 2;
}


void map_create(t_data *data)
{
	int i;
	int j;
	printf("[map_str]\n");
	printf("%s\n", data->map.map_str);

	map_sizecheck(data);
	map_allocate(data);
	map_str_to_array(data);

	printf("row : %d col : %d\n", data->map.row, data->map.col);
	i = 0;

	while (i < data->map.row)
	{
		printf("%s\n", data->map.map_arr[i]);
		i++;
	}
}

void map_parse(char *line,t_data *data)
{
	char *map;
	char *temp;

	map = ft_strjoin(data->map.map_str, line);
	temp = map;
	map = ft_strjoin(map, "\n");
	free(temp);
	data->map.map_str = map;
}
