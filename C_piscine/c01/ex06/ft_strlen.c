/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 18:44:11 by nlee              #+#    #+#             */
/*   Updated: 2020/08/05 10:02:16 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int temp_no;
	int count_str;

	count_str = 0;
	temp_no = 0;
	while (str[temp_no] != '\0')
	{
		count_str++;
		temp_no++;
	}
	return (count_str);
}
