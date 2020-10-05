/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 13:42:15 by nlee              #+#    #+#             */
/*   Updated: 2020/08/09 13:42:17 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	assign_memory(int **map, int **row_gvn, int **col_gvn)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[i] = (int*)malloc(sizeof(int) * 4);
		row_gvn[i] = (int*)malloc(sizeof(int) * 2);
		col_gvn[i] = (int*)malloc(sizeof(int) * 2);
		i++;
	}
}

void	free_memory(int **map, int **row_gvn, int **col_gvn)
{
	int i;

	i = 0;
	while (i < 4)
	{
		free(map[i]);
		free(row_gvn[i]);
		free(col_gvn[i]);
		i++;
	}
	free(map);
	free(row_gvn);
	free(col_gvn);
}
