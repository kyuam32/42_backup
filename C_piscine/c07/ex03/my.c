/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:09:12 by nlee              #+#    #+#             */
/*   Updated: 2020/08/19 16:40:13 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		str_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int		total_len(int size, char **strs, char *sep)
{
	int t_len;
	int i;

	t_len = 0;
	i = 0;
	while (i < size)
	{
		t_len = t_len + str_len(&strs[i]);
		i++;
	}
	t_len = t_len + (size - 1) * str_len(sep) + 1;
	return (t_len);
}

char	*str_cat(char *d, char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (d[i])
		i++;
	while (s[j])
	{
		d[i + j] = s[j];
		j++;
	}
	d[i + j] = 0;
	return (d);
}

void	*clean_mem(char *result, int t_len)
{
	int i;

	i = 0;
	while (i < t_len + 1)
	{
		result[i] = 0;
		i++;
	}
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		t_len;
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	t_len = total_len(size, strs, sep);
	if (size == 0)
	{
		result = (char *)malloc(sizeof(char) * 1);
		result[0] = 0;
		return (result);
	}
	result = (char *)malloc(sizeof(char ) * t_len);
	clean_mem(result, t_len);
	while (i < size)
	{
		str_cat(result, strs[i]);
		if (i != size - 1)
			str_cat(result, sep);
		i++;
	}
	return (result);
}
