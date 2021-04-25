/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:21:31 by minckim           #+#    #+#             */
/*   Updated: 2021/03/09 03:49:41 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int			stack_rot(t_stack *a)
{
	if (a->size > 1)
		a->head = a->head->next;
	return (0);
}

int			stack_rot_rot(t_stack *a, t_stack *b)
{
	stack_rot(a);
	stack_rot(b);
	return (0);
}

int			stack_rot_r(t_stack *a)
{
	if (a->size > 1)
		a->head = a->head->prev;
	return (0);
}

int			stack_rot_rot_r(t_stack *a, t_stack *b)
{
	stack_rot_r(a);
	stack_rot_r(b);
	return (0);
}
