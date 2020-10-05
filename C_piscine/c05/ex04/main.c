/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 22:38:21 by nlee              #+#    #+#             */
/*   Updated: 2020/08/11 22:51:53 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_fibonacci(int index)
{
	int result;

	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	result = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (result);
}

int main(int argc, char **argv)
{
	int n;

	if (argc == 2)
	{
		n = atoi(&argv[1][0]);
		printf("%d\n",ft_fibonacci(n));
	}
}
