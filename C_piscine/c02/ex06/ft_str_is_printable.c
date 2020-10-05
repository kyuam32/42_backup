/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 18:05:38 by nlee              #+#    #+#             */
/*   Updated: 2020/08/05 18:06:29 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			ft_str_is_printable(char *str)
{
	char	*temp;
	int		check;
	int		i;

	temp = str;
	i = 0;
	check = 1;
	while (temp[i] != '\0')
	{
		if (temp[i] < 32 || temp[i] > 126)
		{
			check = 0;
		}
		i++;
	}
	return (check);
}
