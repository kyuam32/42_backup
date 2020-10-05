/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:18:14 by nlee              #+#    #+#             */
/*   Updated: 2020/08/12 20:41:16 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		base_len_err(char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if ((base[i] >= 8 && base[i] <= 13) || base[i] == 32)
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int		base_check(char *str, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (*str == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		str_check(char *str)
{
	int count;

	count = 1;
	if (*str == 0)
		return (0);
	while ((*str >= 8 && *str <= 13) || *str == 32)
	{
		str++;
	}
	while (*str)
	{
		if (*str == '-')
			count = count * -1;
		if ((*str >= 8 && *str <= 13) || *str == 32)
			return (0);
		str++;
	}
	return (count);
}

int		char_to_base(char *str, char *base)
{
	int nb;

	nb = 0;
	while (*str)
	{
		if (base_check(str, base) != -1)
		{
			while (base_check(str, base) != -1)
			{
				nb = nb * base_len_err(base) + base_check(str, base);
				str++;
			}
			return (nb);
		}
		str++;
	}
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	int result;
	int j;
	int k;

	j = 0;
	k = 0;
	if (base_len_err(base) == 0)
		return (0);
	while (base[j])
	{
		k = j + 1;
		while (base[k])
		{
			if (base[j] == base[k])
				return (0);
			k++;
		}
		j++;
	}
	result = str_check(str) * char_to_base(str, base);
	return (result);
}
