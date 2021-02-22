/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:05:07 by namkyu            #+#    #+#             */
/*   Updated: 2021/02/22 16:23:16 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	f_test(format_list *f_list, char *s)
// {
// 	printf("~ ~ ~ ~ ~ [ FORMAT STATUS %s ] ~ ~ ~ ~ ~\n", s);
// 	printf("zero_len    : [%d]\n", f_list->zero_len);
// 	printf("zero_symbol : [%c]\n", f_list->zero_symbol);
// 	printf("width_len   : [%d]\n", f_list->width);
// 	printf("align       : [%d]\n", f_list->align);
// 	printf("precision   : [%d]\n", f_list->precision);
// 	printf("strlen      : [%d]\n", f_list->strlen);
// 	printf("sign        : [%d]\n", f_list->sign);
// 	printf("base        : [%s]\n", f_list->base);
// }

void	reset_flist(format_list *f_list)
{
	f_list->zero_len = 0;
	f_list->zero_symbol = ' ';
	f_list->width = 0;
	f_list->align = RIGHT_ALIGN;
	f_list->precision = 0;
	f_list->strlen = 0;
	f_list->sign = 0;
	f_list->base = NULL;
}

int	ft_printf(const char *format, ...)
{
	format_list		*f_list;
	va_list			ap;
	int				ret;

	ret = 0;
	va_start(ap, format);
	if(!(f_list = (format_list *)malloc(sizeof(format_list))))
		return (0);
	reset_flist(f_list);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			ret++;
		}
		else
			format += ft_printf_parsing_A(format + 1, f_list, &ap, &ret);
		format++;
	}
	free(f_list);
	return (ret);
}

// int	main(void)
// {
// 	char *A;
// 	int	n;
// 	char *str;

// 	A = "ABC%3.pasd";
// 	n = 43;
// 	str = "HELLO";
// 	printf("~~[%s]~~", A);
// 	printf(" // ~~[%p]~~\n", A);

// 	ft_printf(A, A);
// 	return (0);
// }
