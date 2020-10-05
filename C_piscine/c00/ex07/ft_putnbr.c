/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:25:20 by nlee              #+#    #+#             */
/*   Updated: 2020/08/05 17:58:25 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_loop(int nb)
{
	if (nb < 10)
	{
		ft_putchar(nb + '0');
	}
	else if (nb >= 10)
	{
		ft_loop(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_loop(214748364);
			ft_loop(8);
		}
		else
			ft_loop(nb * -1);
	}
	else
		ft_loop(nb);
}
