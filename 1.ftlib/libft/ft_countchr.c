/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:37:08 by nlee              #+#    #+#             */
/*   Updated: 2020/10/13 16:40:07 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countchr(const char *str, int c)
{
	size_t c_count;

	c_count = 0;
	while (*str)
	{
		if (*str == (unsigned char)c)
			c_count++;
		str++;
	}
	return (c_count);
}
