/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 20:47:13 by minckim           #+#    #+#             */
/*   Updated: 2021/03/09 04:02:05 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_status_a(t_stack *a, t_stack *b, int range, int *n_sort)
{
	if (n_sort[6] & visual)
	{
		print_stack_both(a, b, n_sort[6]);
		ft_printf("A: range: %d\n", range);
		ft_printf("A: pivot0: %d\n", n_sort[3]);
		ft_printf("A: pivot1: %d\n", n_sort[4]);
		ft_printf("A: last: %d\n", n_sort[5]);
	}
}

void	print_status_b(t_stack *a, t_stack *b, int range, int *n_sort)
{
	if (n_sort[6] & visual)
	{
		print_stack_both(a, b, n_sort[6]);
		ft_printf("B: range: %d\n", range);
		ft_printf("B: pivot0: %d\n", n_sort[3]);
		ft_printf("B: pivot1: %d\n", n_sort[4]);
		ft_printf("B: last: %d\n", n_sort[5]);
	}
}

void	sort_out_first(t_stack *a, t_stack *b, int range, int *n_sort)
{
	while (range--)
	{
		if (top(a) < n_sort[4])
		{
			instruction_pb(a, b);
			if (top(b) >= n_sort[3])
				n_sort[1]++;
			else
			{
				instruction_rb(a, b);
				n_sort[0]++;
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

void	solve(t_stack *a, t_stack *b, int options)
{
	int		n_sort[6];
	int		range;

	ft_memset(n_sort, 0, sizeof(int) * 3);
	range = a->size;
	find_pivot2(a, range, n_sort + 3);
	n_sort[5] = last_smaller_than_pivot(a, range, n_sort[4]);
	if (options & visual)
		print_status_a(a, b, range, n_sort);
	if (solve_specific_case_a(a, b, range))
		return ;
	sort_out_first(a, b, range, n_sort);
	solve_a(a, b, range - n_sort[1] - n_sort[0], options);
	solve_b(a, b, n_sort[1], options);
	solve_b(a, b, n_sort[0], options);
}

int		main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	int			options;

	options = 0;
	(void)argc;
	initiate(argv, &a, &b, &options);
	if (a.size == 0)
		return (0);
	if (options & visual)
		print_stack_both(&a, &b, options);
	solve(&a, &b, options);
	if (options & visual)
		print_result(&a, &b, options);
	clear_stack(&a);
	clear_stack(&b);
}
