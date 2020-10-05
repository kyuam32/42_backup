/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 23:43:14 by nlee              #+#    #+#             */
/*   Updated: 2020/08/13 14:28:30 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int result;
	int negative_check;

	result = 0;
	negative_check = 1;
	while ((*str >= 8 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative_check *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (negative_check * result);
}
