/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:05:07 by namkyu            #+#    #+#             */
/*   Updated: 2021/02/23 17:38:37 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_flist(t_format_list *f_list)
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
	t_format_list	*f_list;
	va_list			ap;
	int				ret;

	ret = 0;
	va_start(ap, format);
	f_list = (t_format_list *)malloc(sizeof(t_format_list));
	if (f_list == NULL)
		return (-1);
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
	return (ret);
}
