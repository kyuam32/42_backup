/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 13:41:23 by nlee              #+#    #+#             */
/*   Updated: 2020/08/09 13:41:25 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		num_overlap_check(int **map, int row, int col);
int		row_gvn_check_merge(int **map, int row, int **row_gvn);
int		col_gvn_check_merge(int **map, int col, int **col_gvn);

int		coordinate_move(int **map, int *row, int *col)
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

int		solve(int **map, int **row_gvn, int **col_gvn)
{
	int row;
	int col;
	int val;

	val = 1;
	if (!coordinate_move(map, &row, &col))
		return (1);
	while (val <= 4)
	{
		map[row][col] = val;
		if (num_overlap_check(map, row, col))
		{
			if ((row_gvn_check_merge(map, row, row_gvn) &&
						col_gvn_check_merge(map, col, col_gvn)))
			{
				if (solve(map, row_gvn, col_gvn))
					return (1);
			}
		}
		map[row][col] = 0;
		val++;
	}
	return (0);
}
