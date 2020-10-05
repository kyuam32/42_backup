/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 21:20:50 by nlee              #+#    #+#             */
/*   Updated: 2020/08/11 22:31:18 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_recursive_power(int nb, int power)
{
	int result;

	result = 1;
	if (nb < 0 || power < 0)
		return (0);
	if (power != 0)
		result = nb * ft_recursive_power(nb,power - 1);
	return (result);
}

int main(int argc, char** argv)
{
	int n;
	int p;

	n = atoi(&argv[1][0]);
	p = atoi(&argv[2][0]);
	printf("%d\n",n);
	if (argc == 3)
		printf("%d\n",ft_recursive_power(n, p));
}
