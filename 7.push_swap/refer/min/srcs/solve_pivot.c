/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_pivot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:06:37 by minckim           #+#    #+#             */
/*   Updated: 2021/03/09 04:08:49 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				last_smaller_than_pivot(t_stack *stack, int range, int pivot)
{
	t_node	*node;

	node = stack->head;
	while (--range)
	{
		node = node->next;
	}
	while (pivot < node->val)
	{
		node = node->prev;
	}
	return (node->val);
}

int				last_larger_than_pivot(t_stack *stack, int range, int pivot)
{
	t_node	*node;

	node = stack->head;
	while (--range)
	{
		node = node->next;
	}
	while (pivot > node->val)
	{
		node = node->prev;
	}
	return (node->val);
}

int				find_pivot(t_stack *stack, int range)
{
	int		*arr;
	int		pivot;

	if (stack_to_arr(stack, &arr, range) < 0)
		return (0);
	quick_sort(arr, arr + range);
	pivot = arr[range / 2];
	free(arr);
	arr = 0;
	return (pivot);
}

int				find_pivot2(t_stack *stack, int range, int *val)
{
	int		*arr;

	if (stack_to_arr(stack, &arr, range) < 0)
		return (1);
	quick_sort(arr, arr + range);
	val[0] = arr[range / 3];
	val[1] = arr[range * 2 / 3];
	free(arr);
	arr = 0;
	return (0);
}
