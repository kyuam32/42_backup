/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:37:25 by nlee              #+#    #+#             */
/*   Updated: 2020/08/17 15:41:12 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					str_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*str_copy(char *str)
{
	char	*result;
	int		i;

	i = 0;
	result = (char*)malloc(sizeof(char) * str_len(str) + 1);
	if (result == 0)
		return (0);
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str *result;
	int			i;

	result = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (result == 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		result[i].size = str_len(av[i]);
		result[i].str = av[i];
		result[i].copy = str_copy(av[i]);
		i++;
	}
	result[i].str = 0;
	return (result);
}
