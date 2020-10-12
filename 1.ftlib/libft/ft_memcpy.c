/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:03:52 by nlee              #+#    #+#             */
/*   Updated: 2020/10/08 17:27:20 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long dst_ptr;
	unsigned long src_ptr;
	unsigned char temp;

	dst_ptr = (long)dst;
	src_ptr = (long)src;
	if (!(dst_ptr) && !(src_ptr))
		return (NULL);
	while (n > 0)
	{
		temp = ((unsigned char *)src_ptr)[0];
		((unsigned char *)dst_ptr)[0] = temp;
		dst_ptr++;
		src_ptr++;
		n--;
	}
	return (dst);
}
