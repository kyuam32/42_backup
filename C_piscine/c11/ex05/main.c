/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 11:04:53 by nlee              #+#    #+#             */
/*   Updated: 2020/08/21 12:39:36 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nlee.h"

void		oper_selec(int num1, char oper, int num2)
{
	if (oper == '+')
		cal_plus(num1, num2);
	else if (oper == '-')
		cal_min(num1, num2);
	else if (oper == '*')
		cal_multi(num1, num2);
	else if (oper == '/')
		cal_devied(num1, num2);
	else if (oper == '%')
		cal_remain(num1, num2);
	else
		write(1, "0\n", 2);
}

int			main(int ac, char **av)
{
	if (ac == 4)
		oper_selec(ft_atoi(av[1]), av[2][0], ft_atoi(av[3]));
	return (0);
}
