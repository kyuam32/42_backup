/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:47:20 by minckim           #+#    #+#             */
/*   Updated: 2021/03/09 03:57:01 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		case3a(t_stack *a, t_stack *b)
{
	int		val[3];

	val[0] = a->head->val;
	val[1] = a->head->next->val;
	val[2] = a->head->next->next->val;
	if (val[0] < val[2] && val[2] < val[1])
		case3a_021(a, b);
	else if (val[1] < val[0] && val[0] < val[2])
		instruction_sa(a, b);
	else if (val[1] < val[2] && val[2] < val[0])
		case3a_201(a, b);
	else if (val[2] < val[0] && val[0] < val[1])
		case3a_120(a, b);
	else if (val[2] < val[1] && val[1] < val[0])
		case3a_210(a, b);
	return (1);
}

int		case4a(t_stack *a, t_stack *b)
{
	int		val[4];

	val[0] = top(a);
	val[1] = second(a);
	val[2] = a->head->next->next->val;
	val[3] = a->head->next->next->next->val;
	if (val[0] < val[2] && val[2] < val[1] && val[1] < val[3])
	{
		instruction_pb(a, b);
		instruction_sa(a, b);
		instruction_pa(a, b);
		return (1);
	}
	if (val[1] < val[0] && val[0] < val[2] && val[2] < val[3])
	{
		instruction_sa(a, b);
		return (1);
	}
	return (0);
}

int		solve_specific_case_a(t_stack *a, t_stack *b, int range)
{
	if (check_stack(a, range) == 0)
		return (1);
	if (range == 1)
		return (1);
	else if (range == 2)
	{
		if (top(a) > second(a))
		{
			if (top(b) < second(b))
				instruction_ss(a, b);
			else
				instruction_sa(a, b);
		}
		return (1);
	}
	else if (range == 3)
		return (case3a(a, b));
	else if (range == 4)
		return (case4a(a, b));
	return (0);
}

void	sort_out_a(t_stack *a, t_stack *b, int range, int *n_sort)
{
	while (range--)
	{
		if (top(a) < n_sort[4])
		{
			instruction_pb(a, b);
			if (top(b) < n_sort[3])
				n_sort[0]++;
			else
			{
				instruction_rb(a, b);
				n_sort[1]++;
			}
			if (top(b) == n_sort[5])
				break ;
		}
		else
		{
			instruction_ra(a, b);
			n_sort[2]++;
		}
	}
}

void	solve_a(t_stack *a, t_stack *b, int range, int options)
{
	int		n_sort[7];

	ft_memset(n_sort, 0, sizeof(int) * 3);
	n_sort[6] = options;
	find_pivot2(a, range, n_sort + 3);
	n_sort[5] = last_smaller_than_pivot(a, range, n_sort[4]);
	print_status_a(a, b, range, n_sort);
	if (solve_specific_case_a(a, b, range))
		return ;
	sort_out_a(a, b, range, n_sort);
	rewind_stack(a, b, n_sort[2], n_sort[1]);
	solve_a(a, b, range - n_sort[1] - n_sort[0], options);
	solve_b(a, b, n_sort[1], options);
	solve_b(a, b, n_sort[0], options);
}
