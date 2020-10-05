/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 00:07:06 by nlee              #+#    #+#             */
/*   Updated: 2020/08/18 09:19:44 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_board(int *queens)
{
	int		i;
	char	temp;

	i = 0;
	while (i < 10)
	{
		temp = queens[i] + '0';
		write(1, &temp, 1);
		i++;
	}
	write(1, "\n", 1);
}

int		queen_check(int row, int col, int *queens)
{
	int i;
	int abs_row;
	int abs_col;

	i = 0;
	while (i < col)
	{
		if (row == queens[i])
			return (0);
		if (row > queens[i])
			abs_row = row - queens[i];
		else
			abs_row = queens[i] - row;
		abs_col = col - i;
		if (abs_col == abs_row)
			return (0);
		i++;
	}
	return (1);
}

void	fill_board(int col, int *queens, int *count)
{
	int row;

	if (col == 10)
	{
		(*count)++;
		print_board(queens);
		return ;
	}
	row = 0;
	while (row < 10)
	{
		if (queen_check(row, col, queens))
		{
			queens[col] = row;
			fill_board(col + 1, queens, count);
		}
		row++;
	}
}

void	init_board(int *queens)
{
	int i;

	i = 0;
	while (i < 10)
	{
		queens[i] = 0;
		i++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int queens[10];
	int count;

	init_board(queens);
	count = 0;
	fill_board(0, queens, &count);
	return (count);
}
