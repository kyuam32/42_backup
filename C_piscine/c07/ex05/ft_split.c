/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:33:50 by nlee              #+#    #+#             */
/*   Updated: 2020/08/19 14:40:46 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		is_charset(char *str, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (*str == charset[i] && *str != 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int		split_count(char *str, char *charset)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (!(is_charset(&str[i], charset)) && is_charset(&str[i + 1], charset))
			count++;
		i++;
	}
	if (str[i] == 0 && !is_charset(&str[i - 1], charset))
		count++;
	return (count);
}

void	str_cat(char **result, char *temp, int size)
{
	int i;

	i = 0;
	*result = (char *)malloc(sizeof(char) * size + 1);
	while (i < size)
	{
		(*result)[i] = temp[i];
		i++;
	}
	(*result)[i] = 0;
}

char	*init_split(char **result, char *temp, char *charset)
{
	int size;

	size = 0;
	while (is_charset(temp, charset))
		temp++;
	while (!is_charset(&temp[size], charset))
		size++;
	str_cat(result, temp, size);
	return (&temp[size]);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	char	*temp;
	int		i;
	int		pieces;

	i = 0;
	temp = str;
	if (charset[0] == 0)
	{
		result = (char **)malloc(sizeof(char *) * 2);
		while (str[i])
			i++;
		str_cat(&result[0], str, i);
		result[1] = 0;
		return (result);
	}
	pieces = split_count(str, charset);
	result = (char **)malloc(sizeof(char *) * (pieces + 1));
	while (i < pieces)
	{
		temp = init_split(&result[i], temp, charset);
		i++;
	}
	result[pieces] = 0;
	return (result);
}
