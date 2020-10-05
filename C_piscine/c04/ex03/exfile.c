/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:18:14 by nlee              #+#    #+#             */
/*   Updated: 2020/08/12 23:15:34 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		num_check(char *str)
{
	if (*str >= '0' && *str <= '9')
		return (0);
	if (*str >= 'a' && *str <= 'z')
		return (0);
	if (*str >= 'A' && *str <= 'Z')
		return (0);
	return (1);
}

char	*find_num(char *str)
{
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			return (str);
		str++;
	}
	return (0);
}

int		str_check(char *str)
{
	int count;

	count = 1;
	while ((*str >= 8 && *str <= 13) || *str == 32)
	{
		str++;
	}
	while (num_check(str))
	{
		if (*str == '-')
			count = count * -1;
		if ((*str >= 8 && *str <= 13) || *str == 32)
			return (0);
		str++;
	}
	return (count);
}

int		char_to_int(char *str)
{
	int nb;

	nb = 0;
	if (*str == 0)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (nb);
}

int		ft_atoi(char *str)
{
	int result;

	if (*str == 0)
		return (0);
	result = str_check(str) * char_to_int(find_num(str));
	return (result);
}
