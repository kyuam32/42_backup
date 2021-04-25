/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:17:13 by minckim           #+#    #+#             */
/*   Updated: 2021/03/09 03:55:04 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			instruction_pa(t_stack *a, t_stack *b)
{
	(void)b;
	stack_push(a, b);
	ft_printf("pa\n");
}

void			instruction_pb(t_stack *a, t_stack *b)
{
	(void)a;
	stack_push(b, a);
	ft_printf("pb\n");
}

void			instruction_sa(t_stack *a, t_stack *b)
{
	(void)b;
	stack_swap(a);
	ft_printf("sa\n");
}

void			instruction_sb(t_stack *a, t_stack *b)
{
	(void)a;
	stack_swap(b);
	ft_printf("sb\n");
}

void			instruction_ss(t_stack *a, t_stack *b)
{
	stack_swap(a);
	stack_swap(b);
	ft_printf("ss\n");
}
