/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:17:32 by minckim           #+#    #+#             */
/*   Updated: 2021/03/09 03:45:44 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			instruction_ra(t_stack *a, t_stack *b)
{
	(void)b;
	stack_rot(a);
	ft_printf("ra\n");
}

void			instruction_rb(t_stack *a, t_stack *b)
{
	(void)a;
	stack_rot(b);
	ft_printf("rb\n");
}

void			instruction_rr(t_stack *a, t_stack *b)
{
	stack_rot(a);
	stack_rot(b);
	ft_printf("rr\n");
}

void			instruction_rra(t_stack *a, t_stack *b)
{
	(void)b;
	stack_rot_r(a);
	ft_printf("rra\n");
}

void			instruction_rrb(t_stack *a, t_stack *b)
{
	(void)a;
	stack_rot_r(b);
	ft_printf("rrb\n");
}
