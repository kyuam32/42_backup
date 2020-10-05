/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 23:11:44 by nlee              #+#    #+#             */
/*   Updated: 2020/08/11 23:16:20 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb < 2)
		return (0);
	while (i <= nb / 2)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int main (int argc, char **argv)
{
	int n;
	n = atoi(&argv[1][0]);
	printf("%d\n",ft_is_prime(n));
}
