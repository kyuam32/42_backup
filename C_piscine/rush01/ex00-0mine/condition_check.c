/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 13:40:41 by nlee              #+#    #+#             */
/*   Updated: 2020/08/09 13:40:47 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		num_overlap_check(int **map, int row, int col)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (i != col && map[row][i] == map[row][col])
			return (0);
		if (i != row && map[i][col] == map[row][col])
			return (0);
		i++;
	}
	return (1);
}

int		row_gvn_check(int **map, int row, int **row_gvn, int inverse)
{
	int i;
	int k;
	int count;
	int current_height;

	i = 0;
	count = 0;
	current_height = 0;
	while (i < 4)
	{
		k = i;
		if (inverse)
			k = 3 - i;
		if (map[row][k] == 0)
			return (1);
		if (map[row][k] > current_height)
		{
			current_height = map[row][k];
			count++;
		}
		i++;
	}
	if (count == row_gvn[row][inverse])
		return (1);
	return (0);
}

int		col_gvn_check(int **map, int col, int **col_gvn, int inverse)
{
	int i;
	int k;
	int count;
	int current_height;

	i = 0;
	count = 0;
	current_height = 0;
	while (i < 4)
	{
		k = i;
		if (inverse)
			k = 3 - i;
		if (map[k][col] == 0)
			return (1);
		if (map[k][col] > current_height)
		{
			current_height = map[k][col];
			count++;
		}
		i++;
	}
	if (count == col_gvn[col][inverse])
		return (1);
	return (0);
}

int		row_gvn_check_merge(int **map, int row, int **row_gvn)
{
	int is_valid;

	is_valid = row_gvn_check(map, row, row_gvn, 0)
		&& row_gvn_check(map, row, row_gvn, 1);
	return (is_valid);
}

int		col_gvn_check_merge(int **map, int col, int **col_gvn)
{
	int is_valid;

	is_valid = col_gvn_check(map, col, col_gvn, 0)
		&& col_gvn_check(map, col, col_gvn, 1);
	return (is_valid);
}
