/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 18:04:01 by nlee              #+#    #+#             */
/*   Updated: 2020/08/05 18:04:03 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			ft_str_is_uppercase(char *str)
{
	char	*temp;
	int		check;
	int		i;

	temp = str;
	i = 0;
	check = 1;
	while (temp[i] != '\0')
	{
		if (temp[i] < 'A' || temp[i] > 'Z')
		{
			check = 0;
		}
		i++;
	}
	return (check);
}
