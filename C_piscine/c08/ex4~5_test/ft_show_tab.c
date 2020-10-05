/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 16:33:53 by nlee              #+#    #+#             */
/*   Updated: 2020/08/17 16:38:01 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>
#include <stdlib.h>

struct s_stock_str		*ft_strs_to_tab(int ac, char **av);

void					print_int(int size)
{
	char	c;

	if (size < 10)
	{
		c = size + '0';
		write(1, &c, 1);
	}
	else
	{
		print_int(size / 10);
		c = size % 10 + '0';
		write(1, &c, 1);
	}
}

void					print_char(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, &"\n", 1);
}

void					ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str)
	{
		print_char(par[i].str);
		print_int(par[i].size);
		write(1, &"\n", 1);
		print_char(par[i].copy);
		i++;
	}
}
