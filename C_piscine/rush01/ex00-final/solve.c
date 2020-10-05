/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeryul <jaeryul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 13:41:23 by nlee              #+#    #+#             */
/*   Updated: 2020/08/09 22:45:23 by jaeryul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		increase_row_col(int **map, int *row, int *col)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (map[i][j] == 0)
			{
				*row = i;
				*col = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		solve_with_dfs(int **map, int **array_l_r, int **array_u_d)
{
	int row;
	int col;
	int val;

	val = 1;
	if (!increase_row_col(map, &row, &col))
		return (1);
	while (val <= 4)
	{
		map[row][col] = val;
		if (!check_duplicated_row_col(map, row, col))
		{
			if ((check_row(map, row, array_l_r) &&
						check_col(map, col, array_u_d)))
			{
				if (solve_with_dfs(map, array_l_r, array_u_d))
					return (1);
			}
		}
		map[row][col] = 0;
		val++;
	}
	return (0);
}
