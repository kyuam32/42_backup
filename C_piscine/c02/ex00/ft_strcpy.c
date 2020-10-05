/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 18:11:23 by nlee              #+#    #+#             */
/*   Updated: 2020/08/10 13:58:37 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char		*ft_strcpy(char *dest, char *src)
{
	int		index;
	char	*temp;

	index = 0;
	temp = dest;
	while (src[index] != '\0')
	{
		temp[index] = src[index];
		index++;
	}
	temp[index] = '\0';
	return (dest);
}
