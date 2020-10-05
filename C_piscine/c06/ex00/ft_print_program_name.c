/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 00:14:24 by nlee              #+#    #+#             */
/*   Updated: 2020/08/12 00:28:41 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *str)
{
	write(1, str, 1);
}

int		main(int argc, char **argv)
{
	(void)argc;
	while (*argv[0])
	{
		ft_putchar(argv[0]);
		argv[0]++;
	}
	ft_putchar("\n");
}
