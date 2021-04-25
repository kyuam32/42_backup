/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 03:30:39 by minckim           #+#    #+#             */
/*   Updated: 2021/03/09 04:26:56 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "color.h"

int		is_str_digit(const char *str)
{
	while (*str == '-')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str) == 0)
		{
			return (0);
		}
		else
			str++;
	}
	return (1);
}

void	initiate(char **argv, t_stack *a, t_stack *b, int *options)
{
	int		result;

	init_stack(a);
	init_stack(b);
	while (*++argv)
	{
		if (ft_strcmp(*argv, "-v") == 0)
			*options |= visual;
		else if (ft_strcmp(*argv, "-c") == 0)
			*options |= color;
		else if (is_str_digit(*argv))
			result = push_val(a, ft_atoi(*argv));
		else
			result = -1;
		a->head = a->head->next;
		if (result == -1)
		{
			clear_stack(a);
			clear_stack(b);
			ft_printf("Error\n");
			exit(1);
		}
	}
}

void	print_stack(t_stack *a, int options)
{
	t_node	*node;

	node = a->head;
	while (a->head)
	{
		if ((options & color)
		&& ((node->prev->val < node->val) || node == a->head))
			ft_print_num(node->val, 1);
		else if ((options & color) && !(node->prev->val < node->val))
			ft_print_num(node->val, 2);
		else
			ft_print_num(node->val, 0);
		node = node->next;
		if (node == a->head)
			break ;
	}
	ft_putstr_fd("\n", 1);
}

void	print_stack_both(t_stack *a, t_stack *b, int options)
{
	ft_putstr_fd("============================================\n", 1);
	ft_printf("stack a: %d elements\n->", a->size);
	print_stack(a, options);
	ft_printf("stack b: %d elements\n->", b->size);
	print_stack(b, options);
}

void	print_result(t_stack *a, t_stack *b, int options)
{
	if (options & visual)
	{
		print_stack_both(a, b, options);
		if (check_stack(a, a->size) == 0 && b->size == 0)
		{
			if (options & color)
				ft_putstr_fd(GREEN"OK\n"WHITE, 1);
			else
				ft_putstr_fd("OK\n", 1);
		}
		else
		{
			if (options & color)
				ft_putstr_fd(RED"KO\n"WHITE, 1);
			else
				ft_putstr_fd("KO\n", 1);
		}
	}
}
