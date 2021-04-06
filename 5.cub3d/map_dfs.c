/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:20:07 by namkyu            #+#    #+#             */
/*   Updated: 2021/04/06 12:37:20 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int map_search_escape(t_data *data, int **is_visited, int x, int y)
{
	if (x == 0 || y == 0 || x == data->map.col - 1 || y == data->map.col - 1 || data->map.map_arr[y][x] == ' ')
		return (data->crash_report = MAP_DATA_CORRUPTED + 3);
	is_visited[y][x] = 1;

	for (int i = -1; i <= 1; i++)
	{ 
		for (int j = -1; j <= 1; j++)
		{
			int a = x + i;
			int b = y + j;
			if (!(is_visited[b][a]) && data->map.map_arr[b][a] != '1')
				map_search_escape(data, is_visited, a, b);
		}
	}
	return (0);
}

void map_dfs_free(t_data *data)
{
	int i;

	i = 0;
	while (i < data->map.row)
	{
		if (data->map.dfs[i])
			free(data->map.dfs[i]);
		i++;
	}
	if (data->map.dfs)
		free(data->map.dfs);
}

void map_dfs(t_data *data)
{
	int i;
	int j;

	i = 0;
	if (!(data->map.dfs = (int **)malloc(sizeof(int *) * data->map.row)))
		data->crash_report = MEM_ALLOCATE_FAILED;
	while (i < data->map.row)
	{
		j = 0;
		if (!(data->map.dfs[i] = (int *)malloc(sizeof(int) * data->map.col)))
			data->crash_report = MEM_ALLOCATE_FAILED;
		while (j < data->map.col)
		{
			data->map.dfs[i][j] = 0;
			j++;
		}
		i++;
	}
	map_search_escape(data, data->map.dfs, (int)data->player.axis.x, (int)data->player.axis.y);
	map_dfs_free(data);
}
