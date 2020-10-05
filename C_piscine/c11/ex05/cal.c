/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 11:52:11 by nlee              #+#    #+#             */
/*   Updated: 2020/08/21 15:02:34 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nlee.h"

void			cal_plus(int num1, int num2)
{
	long long	result;

	result = num1 + num2;
	display(result);
	write(1, "\n", 1);
}

void			cal_min(int num1, int num2)
{
	long long	result;

	result = num1 - num2;
	display(result);
	write(1, "\n", 1);
}

void			cal_multi(int num1, int num2)
{
	long long	result;

	result = num1 * num2;
	display(result);
	write(1, "\n", 1);
}

void			cal_devied(int num1, int num2)
{
	long long	result;

	if (num2 == 0)
	{
		write(1, "Stop : division by zero", 23);
		write(1, "\n", 1);
		return ;
	}
	result = num1 / num2;
	display(result);
	write(1, "\n", 1);
}

void			cal_remain(int num1, int num2)
{
	long long	result;

	if (num2 == 0)
	{
		write(1, "Stop : modulo by zero", 21);
		write(1, "\n", 1);
		return ;
	}
	result = num1 % num2;
	display(result);
	write(1, "\n", 1);
}
