/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:50:00 by nlee              #+#    #+#             */
/*   Updated: 2020/08/15 17:50:16 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		nb_len(int min, int max)
{
	int a;

	a = max - min;
	if (a > 0)
		return (a);
	return (-a);
}

int		*ft_range(int min, int max)
{
	int *arr;
	int len;
	int i;

	if (min >= max)
		return (0);
	len = nb_len(min, max);
	i = 0;
	arr = (int *)malloc(sizeof(int) * len);
	while (min != max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}
