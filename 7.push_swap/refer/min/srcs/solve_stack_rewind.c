/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_stack_rewind.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:41:35 by minckim           #+#    #+#             */
/*   Updated: 2021/03/09 04:29:12 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rewind_stack_reverse(t_stack *a, t_stack *b, int ra, int rb)
{
	ra = a->size - ra;
	rb = b->size - rb;
	while (ra && rb)
	{
		instruction_rr(a, b);
		ra--;
		rb--;
	}
	while (ra--)
		instruction_ra(a, b);
	while (rb--)
		instruction_rb(a, b);
	return ;
}

void	rewind_stack(t_stack *a, t_stack *b, int ra, int rb)
{
	while (ra && rb)
	{
		instruction_rrr(a, b);
		ra--;
		rb--;
	}
	while (ra--)
		instruction_rra(a, b);
	while (rb--)
		instruction_rrb(a, b);
}
