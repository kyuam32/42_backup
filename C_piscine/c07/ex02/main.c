/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:50:00 by nlee              #+#    #+#             */
/*   Updated: 2020/08/15 18:47:09 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		nb_len(int min, int max)
{
	int a;

	a = max - min;
	if (a > 0)
		return (a);
	return (-a);
}

int		ft_ultimate_range(int **range, int min, int max)
{
	int len;
	int i;

	if (min >= max)
	{
		range = 0;
		return (0);
	}
	len = nb_len(min, max);
	i = 0;
	*range = (int *)malloc(sizeof(int) * len);
	while (min != max)
	{
		range[0][i] = min;
		min++;
		i++;
	}
	return (len);
}

int   main(void)
{

  int* res = NULL;
  int i;
  int size;

  size = ft_ultimate_range(&res, 10, 4);
  printf("is_null? %d\n", res == NULL);
  for (i = 0; i < 5; i++)
          printf("%d,", res[i]);
  printf("\n");
}
