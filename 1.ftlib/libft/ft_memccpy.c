/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:42:30 by nlee              #+#    #+#             */
/*   Updated: 2020/10/08 17:53:46 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned long dst_ptr;
	unsigned long src_ptr;
	unsigned char temp;

	dst_ptr = (long)dst;
	src_ptr = (long)src;
	while (n > 0)
	{
		temp = ((unsigned char *)src_ptr)[0];
		((unsigned char *)dst_ptr)[0] = temp;
		dst_ptr++;
		src_ptr++;
		if (temp == c)
			return ((void *)src_ptr);
		n--;
	}
	return (NULL);
}
