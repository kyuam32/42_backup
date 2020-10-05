/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 17:53:32 by nlee              #+#    #+#             */
/*   Updated: 2020/08/15 09:51:25 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char		*ft_strstr(char *str, char *to_find)
{
	char	*i;
	char	*j;

	while (*str)
	{
		if (*str == *to_find)
		{
			i = str;
			j = to_find;
			while (*i == *j)
			{
				i++;
				j++;
				if (*i == 0)
					return (0);
				if (*j == 0)
					return (str);
			}
		}
		str++;
	}
	return (0);
}
