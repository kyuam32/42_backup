/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:47:08 by minckim           #+#    #+#             */
/*   Updated: 2021/03/09 03:58:22 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "color.h"

char		*ft_itoa_buffer(ssize_t i, char *result)
{
	char	buffer[30];
	char	*result_head;
	char	*buffer_tmp;
	int		sign;

	buffer_tmp = buffer;
	sign = 1;
	if (i < 0)
		sign = -1;
	i *= sign;
	while (42)
	{
		*buffer_tmp++ = "0123456789"[i % 10];
		i /= 10;
		if (!i)
			break ;
	}
	if (sign == -1)
		*buffer_tmp++ = '-';
	result_head = result;
	while (buffer_tmp != buffer)
		*result++ = *--buffer_tmp;
	*result = 0;
	return (result_head);
}

void		ft_print_num(int val, int op_color)
{
	char	buffer[20];
	int		len;

	buffer[0] = ' ';
	ft_itoa_buffer(val, buffer + 1);
	len = ft_strlen(buffer);
	if (op_color == 1)
		ft_putstr_fd(GREEN, 1);
	else if (op_color == 2)
		ft_putstr_fd(RED, 1);
	write(1, buffer, len);
	if (op_color)
		ft_putstr_fd(WHITE, 1);
}
