/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeryul <jaeryul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 13:40:41 by nlee              #+#    #+#             */
/*   Updated: 2020/08/09 22:45:14 by jaeryul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_duplicated_row_col(int **map, int row, int col)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (i != col && map[row][i] == map[row][col])
			return (1);
		if (i != row && map[i][col] == map[row][col])
			return (1);
		i++;
	}
	return (0);
}

int		check_either_l_or_r(int **map, int row, int **array_l_r, int inverse)
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
	if (count == array_l_r[row][inverse])
		return (1);
	return (0);
}

int		check_either_u_or_d(int **map, int col, int **array_u_d, int inverse)
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
	if (count == array_u_d[col][inverse])
		return (1);
	return (0);
}

int		check_row(int **map, int row, int **array_l_r)
{
	int is_valid;

	is_valid = check_either_l_or_r(map, row, array_l_r, 0)
		&& check_either_l_or_r(map, row, array_l_r, 1);
	return (is_valid);
}

int		check_col(int **map, int col, int **array_u_d)
{
	int is_valid;

	is_valid = check_either_u_or_d(map, col, array_u_d, 0)
		&& check_either_u_or_d(map, col, array_u_d, 1);
	return (is_valid);
}
