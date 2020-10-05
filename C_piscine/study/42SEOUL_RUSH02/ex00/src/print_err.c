/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 08:57:44 by michoi            #+#    #+#             */
/*   Updated: 2020/07/19 15:03:33 by dahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int	print_err(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	print_dict_err(void)
{
	write(1, "Dict Error\n", 11);
	return (0);
}

int	print_alloc_err(void)
{
	write(1, "Fail to allocate\n", 17);
	return (0);
}
