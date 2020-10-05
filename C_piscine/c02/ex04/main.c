/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 18:45:54 by nlee              #+#    #+#             */
/*   Updated: 2020/08/09 17:47:56 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			ft_str_is_lowercase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 'a' || str[i] > 'z')
			return (0);
		i++;
	}
	return (1);
}
int main(int argc, char **argv)
{
    char c;

    c = ft_str_is_lowercase(&argv[1][0]) + '0';
    if (argc == 2)
        write(1, &c, 1);
}
