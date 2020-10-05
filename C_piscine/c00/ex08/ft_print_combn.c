/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 11:24:45 by nlee              #+#    #+#             */
/*   Updated: 2020/08/05 15:29:38 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char* fun_arr_init(int n)
{
	int i;
char nbr_init[10];

	i = 0;
	while(n > 0)
	{
		nbr_init[n] = i + '0';
		i++;
		n--;
	}
	return nbr_init;
}

void print(int n)
{
	char* arr_print;

	arr_print = fun_arr_init(n);
	while (n > 0)
	{
		write(1,&arr_print[n-1],1);
		n--;
	}
}

/*
void ft_print_combn(int n)
{
	fuc_arr
}
*/

