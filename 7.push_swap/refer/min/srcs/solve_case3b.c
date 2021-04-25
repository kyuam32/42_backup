/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_case3b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:47:34 by minckim           #+#    #+#             */
/*   Updated: 2021/03/09 04:02:56 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		case3b_012(t_stack *a, t_stack *b)
{
	if (b->size == 3)
	{
		instruction_rb(a, b);
		instruction_sb(a, b);
		instruction_pa(a, b);
		instruction_pa(a, b);
		instruction_pa(a, b);
		return ;
	}
	instruction_rb(a, b);
	instruction_pa(a, b);
	instruction_pa(a, b);
	instruction_rrb(a, b);
	instruction_sa(a, b);
	instruction_pa(a, b);
}

void		case3b_021(t_stack *a, t_stack *b)
{
	if (b->size == 3)
	{
		instruction_rb(a, b);
		instruction_pa(a, b);
		instruction_pa(a, b);
		instruction_pa(a, b);
		return ;
	}
	instruction_rb(a, b);
	instruction_pa(a, b);
	instruction_pa(a, b);
	instruction_rrb(a, b);
	instruction_pa(a, b);
}

void		case3b_102(t_stack *a, t_stack *b)
{
	if (b->size == 3)
	{
		instruction_rrb(a, b);
		instruction_pa(a, b);
		instruction_pa(a, b);
		instruction_pa(a, b);
		return ;
	}
	instruction_pa(a, b);
	instruction_sb(a, b);
	instruction_pa(a, b);
	instruction_sa(a, b);
	instruction_pa(a, b);
}

void		case3b_201(t_stack *a, t_stack *b)
{
	instruction_pa(a, b);
	instruction_sb(a, b);
	instruction_pa(a, b);
	instruction_pa(a, b);
}

void		case3b_120(t_stack *a, t_stack *b)
{
	instruction_sb(a, b);
	instruction_pa(a, b);
	instruction_pa(a, b);
	instruction_pa(a, b);
}
