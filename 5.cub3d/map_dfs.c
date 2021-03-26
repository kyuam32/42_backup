/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dfs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:20:07 by namkyu            #+#    #+#             */
/*   Updated: 2021/03/26 18:46:10 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void map_dfs(t_data *data)
{
	int **is_visited;
	int i;
	int j;

	i = 0;
	is_visited = (int **)malloc(sizeof(int *) * data->map.row);
	while (i < data->map.row)
	{
		j = 0;
		is_visited[i] = (int *)malloc(sizeof(int) * data->map.col);
		while (j < data->map.col)
		{
			is_visited[i][j] = 0;
			j++;
		}
		i++;
	}
	map_search_escape(data, is_visited, (int)data->player.axis.x, (int)data->player.axis.y);
}

int map_search_escape(t_data *data, int **is_visited, int x, int y)
{
	if (x == 0 || y == 0 || x == data->map.col - 1 || y == data->map.col - 1)
		return (data->crash_report = MAP_DATA_CORRUPTED + 3);
	is_visited[y][x] = 1; //현재 위치를 .으로 바꿈

	for (int i = -1; i <= 1; i++)
	{ 
		for (int j = -1; j <= 1; j++)
		{
			int a = x + i;
			int b = y + j; //주변 8자리를 검사
			if (!(is_visited[b][a]) && data->map.map_arr[b][a] != '1')
				map_search_escape(data, is_visited, a, b);
		}
	}
}