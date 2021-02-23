/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:05:07 by namkyu            #+#    #+#             */
/*   Updated: 2021/02/23 14:44:26 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_flist(format_list *f_list)
{
	f_list->zero_len = 0;
	f_list->zero_symbol = ' ';
	f_list->width = 0;
	f_list->align = RIGHT_ALIGN;
	f_list->precision = -1;
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
	va_end(ap);
	system("leaks a.out");
	return (ret);
}

int	main(void)
{
	int *hi;

	ft_printf("[%d]\n[%i]\n[%u]\n[%x]\n[%X]\n[%%]\n[%c]\n[%s]\n[%p]\n", 4, 4, 256, 1234, 1241, 'T', "hello", hi);
	return (0);
}
