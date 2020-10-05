/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exception.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 08:58:03 by michoi            #+#    #+#             */
/*   Updated: 2020/07/19 14:37:45 by dahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"
#include "../include/check_exception.h"
#include "../include/str_func.h"

int			is_number(char *str)
{
	while (*str)
	{
		if (*str > '9' || *str < '0')
			return (0);
		str++;
	}
	return (1);
}

char		*check_exception(int argc, char *argv[])
{
	char	*dict_name;

	dict_name = NULL;
	if (argc != 2 && argc != 3)
		return (0);
	if (!is_number(argv[argc - 1]))
		return (0);
	if (str_cmp(argv[argc - 1], "") == 0)
		return (0);
	if (argc == 2)
		dict_name = "numbers.dict.txt";
	else
		dict_name = argv[1];
	return (dict_name);
}
