/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 08:57:40 by michoi            #+#    #+#             */
/*   Updated: 2020/07/19 15:05:56 by dahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int		str_len(char *str)
{
	int	length;

	length = 0;
	while (*(str + length))
		length++;
	return (length);
}

int		str_cmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1 - str2);
		i++;
	}
	return (0);
}

void	str_cat(char *g_result, char *src)
{
	int i;
	int rlen;

	i = 0;
	rlen = 0;
	while (g_result[rlen] != '\0')
		rlen++;
	while (src[i] != '\0')
	{
		g_result[rlen] = src[i];
		g_result++;
		i++;
	}
	g_result[rlen] = ' ';
	g_result[rlen + 1] = src[i];
}
