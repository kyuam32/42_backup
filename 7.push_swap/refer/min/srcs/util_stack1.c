/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:19:49 by minckim           #+#    #+#             */
/*   Updated: 2021/03/09 04:04:40 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void		init_stack(t_stack *stack)
{
	stack->head = 0;
	stack->size = 0;
}

int			push_val(t_stack *stack, int val)
{
	t_node		*node;

	node = malloc(sizeof(t_node));
	node->val = val;
	if (!node)
		return (-1);
	push(stack, node);
	return (0);
}

void		push(t_stack *stack, t_node *node)
{
	t_node	*front;
	t_node	*back;

	++stack->size;
	if (!stack->head)
	{
		node->next = node;
		node->prev = node;
		stack->head = node;
		return ;
	}
	front = stack->head;
	back = stack->head->prev;
	front->prev = node;
	back->next = node;
	node->prev = back;
	node->next = front;
	stack->head = node;
}

void		clear_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*next;

	node = stack->head;
	if (!node)
		return ;
	while (42)
	{
		next = node->next;
		free(node);
		node = next;
		if (node == stack->head)
			return ;
	}
}
