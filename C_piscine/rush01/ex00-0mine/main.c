/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 13:41:10 by nlee              #+#    #+#             */
/*   Updated: 2020/08/09 13:41:13 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	assign_memory(int **map, int **row_gvn, int **col_gvn);
int		input_check(int argc, char *argv[]);
void	input_to_array(char *argv[], int **row_gvn, int **col_gvn);
void	init_map(int **map);
int		solve(int **map, int **row_gvn, int **col_gvn);
void	print_map(int **map);
void	free_memory(int **map, int **row_gvn, int **col_gvn);

int		main(int argc, char *argv[])
{
	int	**map;
	int	**row_gvn;
	int	**col_gvn;

	map = (int**)malloc(sizeof(int*) * 4);
	row_gvn = (int**)malloc(sizeof(int*) * 4);
	col_gvn = (int**)malloc(sizeof(int*) * 4);
	assign_memory(map, row_gvn, col_gvn);
	if (!input_check(argc, argv))
	{
		write(1, "Error\n", 6);
		free_memory(map, row_gvn, col_gvn);
		return (1);
	}
	input_to_array(argv, row_gvn, col_gvn);
	init_map(map);
	if (solve(map, row_gvn, col_gvn))
		print_map(map);
	else
		write(1, "Error\n", 6);
	free_memory(map, row_gvn, col_gvn);
	return (0);
}
