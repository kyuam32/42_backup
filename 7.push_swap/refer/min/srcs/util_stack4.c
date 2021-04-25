/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:23:21 by minckim           #+#    #+#             */
/*   Updated: 2021/03/09 04:28:20 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int			check_stack(t_stack *a, int range)
{
	t_node	*node;

	node = a->head;
	if (!node)
		return (-1);
	if (a->size == 1)
		return (0);
	while (node->next != a->head && range--)
	{
		if (node->val > node->next->val)
		{
			return (-1);
		}
		node = node->next;
	}
	return (0);
}

int			stack_to_arr(t_stack *stack, int **arr, int range)
{
	int			size;
	int			*tmp;
	t_node		*node;

	size = range;
	if (!size)
		return (0);
	node = stack->head;
	*arr = malloc(sizeof(int) * size);
	if (!*arr)
		return (-1);
	tmp = *arr;
	while (size--)
	{
		*tmp++ = node->val;
		node = node->next;
	}
	return (0);
}

int			stack_swap(t_stack *a)
{
	if (a->size > 1)
		swap_int(&a->head->val, &a->head->next->val);
	return (0);
}

int			stack_swap_swap(t_stack *a, t_stack *b)
{
	stack_swap(a);
	stack_swap(b);
	return (0);
}
