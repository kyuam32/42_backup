/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:05:07 by namkyu            #+#    #+#             */
/*   Updated: 2021/02/16 19:48:03 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void    print_non_arg(const char *c)
// {
//     write(1, c, 1);
// }

format_list *init_flist()
{
    format_list *f_list;

    if(!(f_list = (format_list *)malloc(sizeof(format_list))))
        return (0);
        
    return (f_list);
}


void    reset_flist(format_list *f_list)
{


    f_list->flag = 0;    
    f_list->zero_len = 0;
    f_list->zero_symbol = ' ';
    f_list->width_len = 0;
    f_list->align = _RIGHT_ALIGN;
    f_list->precision = 0
    f_list->base = 10;

}

int     ft_printf_parsing(const char *format, format_list *f_list, va_list *ap)
{
    int i;
    i = 0;

    if (format[i] == '-' || format[i] == '0')
//change list(ZERO_LEN & ZERO_SYMBOL & ALIGN) data than i++
    if (ft_isdigit(format[i]))
//change list(width_len) data than i++
    if (format[i] == '.')
//change list(precision) data than i++
    if (format[i] == 'd' || format[i] == 'i')
//print signed num
    else if (format[i] =='u' || format[i] == 'x' || format[i] == 'X')
//print unsigned num
    else if (format[i] == '%')
    else if (format[i] == 's')
    else if (format[i] == 'c')
    else if (format[i] == 'p')
    else
        return (_WRONG_FORMAT);
    return (1);
}


int     ft_printf(const char *format, ...)
{
    char            *f_adress;
    format_list     *f_list;
    va_list         ap;
    int             ret;

    va_start(ap, format);
    if(!(f_list = init_flist()));
        return(-1);
    f_adress = format;
    while (*f_adress)
    {
        if (*f_adress != '%')
            write(1, f_adress, 1);
        else
            f_adress = ft_printf_parsing(f_adress + 1, &f_list, &ap);
        f_adress++;
    }
    return (0);
}

int     main()
{
    ft_printf("\ndosajei호뱌뱌21");
}