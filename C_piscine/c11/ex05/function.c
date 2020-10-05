/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuction.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 14:36:56 by nlee              #+#    #+#             */
/*   Updated: 2020/08/21 12:23:40 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nlee.h"

void		display(long long result)
{
	char num;

	if (result < 0)
	{
		write(1, "-", 1);
		result *= -1;
	}
	if (result < 10)
	{
		num = result + '0';
		write(1, &num, 1);
	}
	else if (result >= 10)
	{
		display(result / 10);
		display(result % 10);
	}
}

int			check_char(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	if (c == '-')
		return (-1);
	if (c == '+')
		return (-2);
	if (c >= '0' && c <= '9')
		return (2);
	return (0);
}

int			ft_atoi(char *str)
{
	int index;
	int count;
	int result;

	index = 0;
	while (check_char(str[index]) == 1)
		index++;
	count = 0;
	while (check_char(str[index]) < 0)
	{
		if (check_char(str[index]) == -1)
			count++;
		index++;
	}
	if (str[index] < '0' || str[index] > '9')
		return (0);
	result = str[index++] - '0';
	while (check_char(str[index]) == 2)
		result = result * 10 + str[index++] - '0';
	if (count % 2 == 1)
		result *= -1;
	return (result);
}
