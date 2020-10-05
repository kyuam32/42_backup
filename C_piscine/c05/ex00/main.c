/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 21:20:50 by nlee              #+#    #+#             */
/*   Updated: 2020/08/11 21:43:37 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_iterative_factorial(int nb)
{
	int result;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	result = 1;
	while (nb != 0)
	{
		result = result * nb;
		nb--;
	}
	return (result);
}

int main(int argc, char** argv)
{
	int n;

	n = atoi(&argv[1][0]);
	printf("%d\n",n);
	if (argc == 2)
		printf("%d\n",ft_iterative_factorial(n));
}
