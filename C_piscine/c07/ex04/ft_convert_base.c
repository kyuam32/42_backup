/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 21:38:46 by nlee              #+#    #+#             */
/*   Updated: 2020/08/18 19:07:02 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			base_check(char *bs, char *s);
int			str_len(char *str);
char		base_change(char *str, char *base);

int			base_invalid(char *base)
{
	int	i;
	int j;

	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-'
				|| base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int			ft_atoi(char *str, char *base)
{
	int result;
	int minus;

	result = 0;
	minus = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (base_check(base, str))
	{
		result = result * str_len(base) + base_change(str, base);
		str++;
	}
	return (minus * result);
}

int			count_size(long long num, char *base_to)
{
	int size;

	size = 0;
	if (num == 0)
		return (size = 1);
	while (num > 0)
	{
		num = num / str_len(base_to);
		size++;
	}
	return (size);
}

char		*init_convert(char *result, long long num, char *base_to, int size)
{
	result[size] = 0;
	size--;
	if (num == 0)
	{
		result[size] = base_to[0];
		return (result);
	}
	while (num > 0)
	{
		result[size] = base_to[num % str_len(base_to)];
		num = num / str_len(base_to);
		size--;
	}
	return (result);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	num;
	int			size;
	char		*result;

	if (base_invalid(base_from) || base_invalid(base_to))
		return (0);
	num = ft_atoi(nbr, base_from);
	if (num < 0)
	{
		num *= -1;
		size = count_size(num, base_to) + 1;
		result = (char *)malloc(sizeof(char) * size);
		result[0] = '-';
	}
	else
	{
		size = count_size(num, base_to);
		result = (char *)malloc(sizeof(char) * size);
	}
	return (init_convert(result, num, base_to, size));
}
