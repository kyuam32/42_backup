/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:20:49 by minckim           #+#    #+#             */
/*   Updated: 2021/03/09 04:09:16 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

t_node		*pop(t_stack *stack)
{
	t_node	*front;
	t_node	*back;
	t_node	*result;

	result = stack->head;
	front = stack->head->next;
	back = stack->head->prev;
	front->prev = back;
	back->next = front;
	stack->head = front;
	if (!--stack->size)
	{
		stack->head = 0;
	}
	return (result);
}

int			top(t_stack *stack)
{
	return (stack->head->val);
}

int			second(t_stack *stack)
{
	return (stack->head->next->val);
}

int			stack_push(t_stack *a, t_stack *b)
{
	if (b->size)
		push(a, pop(b));
	return (0);
}
