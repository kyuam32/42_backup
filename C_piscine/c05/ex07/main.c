/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 23:11:44 by nlee              #+#    #+#             */
/*   Updated: 2020/08/13 01:23:56 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_find_next_prime(int nb)
{
	int i;

	i = 2;
	if (nb < 2)
		return (2);
	while (i <= nb / i)
	{
		if (nb % i == 0)
			nb = ft_find_next_prime(nb + 1);
		i++;
	}
	return (nb);
}

int main (int argc, char **argv)
{
	int n;
	n = atoi(&argv[1][0]);
	printf("%d\n",ft_find_next_prime(n));
}
