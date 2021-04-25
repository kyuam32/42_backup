/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_case3a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:47:34 by minckim           #+#    #+#             */
/*   Updated: 2021/03/09 04:03:28 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		case3a_021(t_stack *a, t_stack *b)
{
	instruction_ra(a, b);
	instruction_sa(a, b);
	instruction_rra(a, b);
}

void		case3a_201(t_stack *a, t_stack *b)
{
	if (a->size == 3)
		instruction_ra(a, b);
	else
	{
		instruction_sa(a, b);
		instruction_ra(a, b);
		instruction_sa(a, b);
		instruction_rra(a, b);
	}
}

void		case3a_120(t_stack *a, t_stack *b)
{
	if (a->size == 3)
		instruction_rra(a, b);
	else
	{
		instruction_ra(a, b);
		instruction_ra(a, b);
		instruction_pb(a, b);
		instruction_rra(a, b);
		instruction_rra(a, b);
		instruction_pa(a, b);
	}
}

void		case3a_210(t_stack *a, t_stack *b)
{
	if (a->size == 3)
	{
		instruction_sa(a, b);
		instruction_rra(a, b);
	}
	else
	{
		instruction_sa(a, b);
		instruction_ra(a, b);
		instruction_sa(a, b);
		instruction_rra(a, b);
		instruction_sa(a, b);
	}
}
