/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeryul <jaeryul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 13:41:10 by nlee              #+#    #+#             */
/*   Updated: 2020/08/09 22:45:17 by jaeryul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		main(int argc, char *argv[])
{
	int	**map;
	int	**array_l_r;
	int	**array_u_d;

	map = (int**)malloc(sizeof(int*) * 4);
	array_l_r = (int**)malloc(sizeof(int*) * 4);
	array_u_d = (int**)malloc(sizeof(int*) * 4);
	assign_memory(map, array_l_r, array_u_d);
	if (!check_argument(argc, argv))
	{
		write(1, "Error\n", 6);
		free_memory(map, array_l_r, array_u_d);
		return (1);
	}
	put_into_arrays(argv, array_l_r, array_u_d);
	init_map_to_zero(map);
	if (solve_with_dfs(map, array_l_r, array_u_d))
		print_map(map);
	else
		write(1, "Error\n", 6);
	free_memory(map, array_l_r, array_u_d);
	return (0);
}
