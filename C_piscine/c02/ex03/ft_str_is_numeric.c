/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 11:06:02 by nlee              #+#    #+#             */
/*   Updated: 2020/08/05 11:08:02 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			ft_str_is_numeric(char *str)
{
	char	*temp;
	int		check;
	int		i;

	temp = str;
	i = 0;
	check = 1;
	while (temp[i] != '\0')
	{
		if (temp[i] < '0' || temp[i] > '9')
		{
			check = 0;
		}
		i++;
	}
	return (check);
}
