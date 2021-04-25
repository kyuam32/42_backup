/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 18:18:25 by minckim           #+#    #+#             */
/*   Updated: 2021/03/09 04:20:06 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include "color.h"

int			instruction_processor(char *line, t_stack *a, t_stack *b)
{
	if (ft_strcmp(line, "pa") == 0)
		return (stack_push(a, b));
	else if (ft_strcmp(line, "pb") == 0)
		return (stack_push(b, a));
	else if (ft_strcmp(line, "sa") == 0)
		return (stack_swap(a));
	else if (ft_strcmp(line, "sb") == 0)
		return (stack_swap(b));
	else if (ft_strcmp(line, "ss") == 0)
		return (stack_swap_swap(a, b));
	else if (ft_strcmp(line, "ra") == 0)
		return (stack_rot(a));
	else if (ft_strcmp(line, "rb") == 0)
		return (stack_rot(b));
	else if (ft_strcmp(line, "rr") == 0)
		return (stack_rot_rot(a, b));
	else if (ft_strcmp(line, "rra") == 0)
		return (stack_rot_r(a));
	else if (ft_strcmp(line, "rrb") == 0)
		return (stack_rot_r(b));
	else if (ft_strcmp(line, "rrr") == 0)
		return (stack_rot_rot_r(a, b));
	else
		return (err);
}

int			instruction_recv(t_stack *a, t_stack *b, int *options)
{
	char	*line;
	int		result;

	line = 0;
	result = get_next_line(0, &line);
	if (result < 0 || !line)
		return (err);
	if (!*line)
	{
		free(line);
		return (eof);
	}
	result = 0;
	if (ft_strcmp(line, "-v") == 0)
		*options |= visual;
	else if (ft_strcmp(line, "-c") == 0)
		*options |= color;
	else
		result = instruction_processor(line, a, b);
	if ((*options & visual) && (*options & color))
		ft_printf("Instructoin: %s%s%s\n", BLUE, line, WHITE);
	else if (*options & visual)
		ft_printf("Instructoin: %s\n", line);
	free(line);
	return (result);
}

int			core(t_stack *a, t_stack *b, int *options)
{
	int		result;

	while (42)
	{
		result = instruction_recv(a, b, options);
		if (result != 0)
			break ;
		if (*options & visual)
			print_stack_both(a, b, *options);
	}
	return (result);
}

int			main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	int			options;
	int			result;

	(void)argc;
	options = 0;
	initiate(argv, &a, &b, &options);
	if (a.size == 0)
		return (0);
	if (options & visual)
		print_stack_both(&a, &b, options);
	result = core(&a, &b, &options);
	if (result == err)
		ft_printf("Error\n");
	else if (check_stack(&a, a.size) == 0 && b.size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
