/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:43:38 by nlee              #+#    #+#             */
/*   Updated: 2020/08/10 21:48:59 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int		ft_strlen(char *src)
{
	unsigned int	i;

	i = 0;
	while (*src)
	{
		i++;
		src++;
	}
	return (i);
}

unsigned int		ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (size < dest_len + 1)
		return (size + src_len);
	if (size > dest_len + 1)
	{
		while (src[i] != '\0' && dest_len + 1 + i < size)
		{
			dest[dest_len + i] = src[i];
			i++;
		}
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
