/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:29:45 by nlee              #+#    #+#             */
/*   Updated: 2020/08/11 20:12:00 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putstr_non_printable(char *str)
{
	int				i;
	char			*hexa_trans;
	unsigned char	c;

	i = 0;
	hexa_trans = "0123456789abcdef";
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &(str[i]), 1);
		else
		{
			c = str[i];
			write(1, "\\", 1);
			write(1, &hexa_trans[c / 16], 1);
			write(1, &hexa_trans[c % 16], 1);
		}
		i++;
	}
}
