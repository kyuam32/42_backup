/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:06:43 by namkyu            #+#    #+#             */
/*   Updated: 2021/02/16 18:47:18 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h> //나중에 지워라
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft.h"



# define _WRONG_FORMAT -1
# define _RIGHT_ALIGN 1
# define _LEFT_ALIGN -1


typedef struct _format_list
{
    int     zero_len;
    char    zero_symbol;
    int     width_len;
    int     align;
    int     precision;
    int     base;

} format_list;

#endif