/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 00:29:51 by nlee              #+#    #+#             */
/*   Updated: 2020/08/12 00:40:08 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	while (argc != 1)
	{
		put_char(argv[i]);
		i++;
		argc--;
	}
}
