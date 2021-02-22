/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:11:19 by namkyu            #+#    #+#             */
/*   Updated: 2021/02/22 15:23:05 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_numbers(unsigned long long num, int base, char *base_str)
{
	if (num >= base)
		print_numbers(num / base, base, base_str);
	write(1, &base_str[num % base], 1);
}

void	print_str(format_list *f_list, const char *str)
{
	int i;

	i= 0;
	while(i < f_list->strlen)
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		print_precision(format_list *f_list)
{
	int i;

	i = 0;
	if (f_list->sign < 0)
		write(1, "-", 1);
	while (i < f_list->precision - f_list->strlen)
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}

int		print_width(format_list *f_list)
{
	int i;
	int print_len;
	
	i = 0;
	if (f_list->precision > f_list->strlen)
		print_len = f_list->width - f_list->precision;
	else
		print_len = f_list->width - f_list->strlen;
	if (f_list->sign < 0)
		print_len -= 1;
	while (i < print_len)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int	init_num_case(format_list *f_list, unsigned long long num)
{
	int	printed_char_len;

	printed_char_len = 0;
	if (f_list->align == LEFT_ALIGN)
	{
		printed_char_len += print_precision(f_list);
		print_numbers(num, ft_strlen(f_list->base), f_list->base);
		printed_char_len += print_width(f_list);
	}
	else if (f_list->align == RIGHT_ALIGN)
	{
		printed_char_len += print_width(f_list);
		printed_char_len += print_precision(f_list);
		print_numbers(num, ft_strlen(f_list->base), f_list->base);
	}
	printed_char_len += f_list->strlen;
	return (printed_char_len);
}