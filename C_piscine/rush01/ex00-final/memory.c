/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeryul <jaeryul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 13:42:15 by nlee              #+#    #+#             */
/*   Updated: 2020/08/09 22:45:22 by jaeryul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	assign_memory(int **map, int **array_l_r, int **array_u_d)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[i] = (int*)malloc(sizeof(int) * 4);
		array_l_r[i] = (int*)malloc(sizeof(int) * 2);
		array_u_d[i] = (int*)malloc(sizeof(int) * 2);
		i++;
	}
}

void	free_memory(int **map, int **array_l_r, int **array_u_d)
{
	int i;

	i = 0;
	while (i < 4)
	{
		free(map[i]);
		free(array_l_r[i]);
		free(array_u_d[i]);
		i++;
	}
	free(map);
	free(array_l_r);
	free(array_u_d);
}
