/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:39:19 by nlee              #+#    #+#             */
/*   Updated: 2020/10/08 17:50:21 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned long temp;

	temp = (long)ptr;
	while (num > 0)
	{
		((unsigned char *)temp)[0] = value;
		temp++;
		num--;
	}
	return (ptr);
}

