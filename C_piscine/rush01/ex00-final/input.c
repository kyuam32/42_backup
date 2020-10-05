/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeryul <jaeryul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 13:42:02 by nlee              #+#    #+#             */
/*   Updated: 2020/08/09 22:45:15 by jaeryul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		check_argument(int argc, char *argv[])
{
	int i;

	i = 0;
	if (argc != 2)
		return (0);
	while (argv[1][i])
	{
		if (i == 0 || i % 2 == 0)
		{
			if (!(argv[1][i] >= '1' && argv[1][i] <= '4'))
				return (0);
		}
		else
		{
			if (argv[1][i] != ' ')
				return (0);
		}
		i++;
	}
	i = 0;
	while (argv[1][i])
		i++;
	if (i != 31)
		return (0);
	return (1);
}

void	put_into_arrays(char *argv[], int **array_l_r, int **array_u_d)
{
	int i;
	int a;
	int b;
	int c;
	int d;

	i = 0;
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	while (i < 4)
	{
		a = i * 2;
		b = (i + 4) * 2;
		c = (i + 8) * 2;
		d = (i + 12) * 2;
		array_u_d[i][0] = argv[1][a] - '0';
		array_u_d[i][1] = argv[1][b] - '0';
		array_l_r[i][0] = argv[1][c] - '0';
		array_l_r[i][1] = argv[1][d] - '0';
		i++;
	}
}
