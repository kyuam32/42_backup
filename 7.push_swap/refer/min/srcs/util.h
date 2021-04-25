/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 03:30:36 by minckim           #+#    #+#             */
/*   Updated: 2021/03/09 04:09:42 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H
# include "../libft/libft.h"

typedef struct		s_node
{
	int				val;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct		s_stack
{
	t_node			*head;
	int				size;
}					t_stack;

enum				e_instructions
{
	err = -1,
	eof = 1,
};

enum				e_options
{
	non = 0,
	visual = 1,
	color = 2,
};

/*
**	util.c---------------------------------------------------------------------
*/
void				initiate(char **argv, t_stack *a, t_stack *b, int *options);
void				print_stack(t_stack *a, int options);
void				print_stack_both(t_stack *a, t_stack *b, int options);
void				print_result(t_stack *a, t_stack *b, int options);
/*
**	print_num.c----------------------------------------------------------------
*/
void				ft_print_num(int val, int op_color);
/*
**	sort.c---------------------------------------------------------------------
*/
void				swap_int(int *a, int *b);
void				quick_sort(int *left, int *right);
/*
**	---------------------------------------------------------------------------
**	stack
**	---------------------------------------------------------------------------
*/
/*
**	util_stack1.c--------------------------------------------------------------
*/
void				init_stack(t_stack *a);
int					push_val(t_stack *a, int val);
void				push(t_stack *a, t_node *node);
void				clear_stack(t_stack *a);
/*
**	util_stack2.c--------------------------------------------------------------
*/
t_node				*pop(t_stack *a);
int					top(t_stack *a);
int					second(t_stack *a);
int					stack_push(t_stack *a, t_stack *b);
/*
**	util_stack3.c--------------------------------------------------------------
*/
int					stack_rot(t_stack *a);
int					stack_rot_r(t_stack *a);
int					stack_rot_rot(t_stack *a, t_stack *b);
int					stack_rot_rot_r(t_stack *a, t_stack *b);
/*
**	util_stack4.c--------------------------------------------------------------
*/
int					stack_swap(t_stack *a);
int					stack_swap_swap(t_stack *a, t_stack *b);
int					check_stack(t_stack *a, int range);
int					stack_to_arr(t_stack *a, int **arr, int range);
#endif
