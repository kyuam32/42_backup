/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:17:54 by minckim           #+#    #+#             */
/*   Updated: 2021/03/09 03:45:51 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			instruction_rrr(t_stack *a, t_stack *b)
{
	stack_rot_r(a);
	stack_rot_r(b);
	ft_printf("rrr\n");
}
