/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:03:54 by minckim           #+#    #+#             */
/*   Updated: 2021/03/09 04:11:06 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		case3b(t_stack *a, t_stack *b)
{
	int		val[3];

	val[0] = b->head->val;
	val[1] = b->head->next->val;
	val[2] = b->head->next->next->val;
	if (val[0] < val[1] && val[1] < val[2])
		case3b_012(a, b);
	if (val[0] < val[2] && val[2] < val[1])
		case3b_021(a, b);
	else if (val[1] < val[0] && val[0] < val[2])
		case3b_102(a, b);
	else if (val[1] < val[2] && val[2] < val[0])
		case3b_201(a, b);
	else if (val[2] < val[0] && val[0] < val[1])
		case3b_120(a, b);
	else if (val[2] < val[1] && val[1] < val[0])
	{
		instruction_pa(a, b);
		instruction_pa(a, b);
		instruction_pa(a, b);
	}
	return (1);
}

int		solve_specific_case_b(t_stack *a, t_stack *b, int range)
{
	if (range == 1)
	{
		instruction_pa(a, b);
		return (1);
	}
	else if (range == 2)
	{
		if (top(b) < second(b))
		{
			if (top(a) > second(a))
				instruction_ss(a, b);
			else
				instruction_sb(a, b);
		}
		instruction_pa(a, b);
		instruction_pa(a, b);
		return (1);
	}
	else if (range == 3)
	{
		return (case3b(a, b));
	}
	return (0);
}

void	sort_out_b(t_stack *a, t_stack *b, int range, int *n_sort)
{
	while (range--)
	{
		if (top(b) >= n_sort[3])
		{
			instruction_pa(a, b);
			if (top(a) < n_sort[4])
			{
				instruction_ra(a, b);
				n_sort[1]++;
			}
			else
				n_sort[2]++;
			if (top(a) == n_sort[5])
				break ;
		}
		else
		{
			instruction_rb(a, b);
			n_sort[0]++;
		}
	}
}

void	solve_b(t_stack *a, t_stack *b, int range, int options)
{
	int		n_sort[7];

	ft_memset(n_sort, 0, sizeof(int) * 3);
	n_sort[6] = options;
	find_pivot2(b, range, n_sort + 3);
	n_sort[5] = last_larger_than_pivot(b, range, n_sort[3]);
	print_status_b(a, b, range, n_sort);
	if (solve_specific_case_b(a, b, range))
		return ;
	sort_out_b(a, b, range, n_sort);
	solve_a(a, b, n_sort[2], options);
	rewind_stack(a, b, n_sort[1], n_sort[0]);
	solve_a(a, b, n_sort[1], options);
	solve_b(a, b, range - n_sort[1] - n_sort[2], options);
}
