/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:36:15 by namkyu            #+#    #+#             */
/*   Updated: 2021/02/22 15:51:37 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void num_data_input(unsigned long long num, format_list *f_list)
{
    int             i;

    i = 1;
    while (num >= ft_strlen(f_list->base))
    {
        num = num / ft_strlen(f_list->base);
        i++;
    }
    f_list->strlen = i;
}

void str_data_input(const char *str, format_list *f_list)
{
    if (ft_strlen(str) <= f_list->precision || f_list->precision == 0)
        f_list->strlen = ft_strlen(str);
    else
        f_list->strlen = f_list->precision;
}