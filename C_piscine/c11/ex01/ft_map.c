/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 01:26:07 by nlee              #+#    #+#             */
/*   Updated: 2020/08/21 13:44:15 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int *result;
	int i;

	result = (int *)malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		result[i] = f(tab[i]);
		i++;
	}
	return (result);
}
