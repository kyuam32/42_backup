/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 17:53:14 by nlee              #+#    #+#             */
/*   Updated: 2020/08/10 15:37:29 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char				*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*d;
	char			*s;
	unsigned int	n;

	d = dest;
	s = src;
	n = nb;
	while (*d)
		d++;
	while (*s != 0 && n--)
	{
		*d = *s;
		d++;
		s++;
	}
	*d = 0;
	return (dest);
}
