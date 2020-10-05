/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:09:38 by nlee              #+#    #+#             */
/*   Updated: 2020/08/15 17:09:40 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strlen(char *src)
{
	int		i;

	i = 0;
	while (*src)
	{
		i++;
		src++;
	}
	return (i);
}

char		*ft_strdup(char *src)
{
	char	*duple;
	int		i;

	i = 0;
	duple = (char *)malloc(sizeof(char) * ft_strlen(src));
	while (src[i])
	{
		duple[i] = src[i];
		i++;
	}
	duple[i] = 0;
	return (duple);
}
