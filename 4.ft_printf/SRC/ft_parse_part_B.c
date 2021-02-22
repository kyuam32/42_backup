/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_part_B.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:45:34 by namkyu            #+#    #+#             */
/*   Updated: 2021/02/22 16:25:32 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int case_integer(format_list *f_list, va_list *ap)
{
	unsigned long long	num;
	int					temp;

	temp = va_arg(*ap, int);
	if (temp < 0)
	{
		num = temp * -1;
		f_list->sign = -1;
	}
	else
		num = temp;
	f_list->base = "0123456789";
	num_data_input(num, f_list);
	return (init_num_case(f_list, num));
}

int case_undsigned_int(const char *format, format_list *f_list, va_list *ap)
{
	unsigned long long		num;

	num = (unsigned long long)va_arg(*ap, unsigned int);
	if (*format == 'u')
		f_list->base = "0123456789";
	else if (*format == 'x')
		f_list->base = "0123456789abcdef";
	else if (*format == 'X')
		f_list->base = "0123456789ABCDEF";
	num_data_input(num, f_list);
	return (init_num_case(f_list, num));
}

int case_character(const char *format, format_list *f_list, va_list *ap)
{
	int printed_char_len;
	unsigned char c;

	printed_char_len = 0;
	f_list->precision = 0;
	if (*format == '%')
		c = '%';
	else
		c = (unsigned char)va_arg(*ap, int);
	f_list->strlen = 1;
	if (f_list->align == LEFT_ALIGN)
	{
		write(1, &c, 1);
		printed_char_len += print_width(f_list);
	}
	else if (f_list->align == RIGHT_ALIGN)
	{
		printed_char_len += print_width(f_list);
		write(1, &c, 1);
	}
	return (printed_char_len + 1);
}

int case_string(format_list *f_list, va_list *ap)
{
	int printed_char_len;
	const char *str;

	printed_char_len = 0;
	str = va_arg(*ap, const char *);
	str_data_input(str, f_list);
	if (f_list->align == LEFT_ALIGN)
	{
		print_str(f_list, str);
		printed_char_len += print_width(f_list);
	}
	else if (f_list->align == RIGHT_ALIGN)
	{
		printed_char_len += print_width(f_list);
		print_str(f_list, str);
	}
	printed_char_len += f_list->strlen;
	return (printed_char_len);
}

int case_pointer(format_list *f_list, va_list *ap)
{
	int printed_char_len;
	unsigned long long num;

	num = (unsigned long long)va_arg(*ap, void *);
	f_list->precision = 0;
	f_list->base = "0123456789abcdef";
	num_data_input(num, f_list);
	write(1, &"0x", 2);
	return (init_num_case(f_list, num) + 2);
}