/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:42:49 by minckim           #+#    #+#             */
/*   Updated: 2021/03/09 04:27:29 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "util.h"

/*
** ----------------------------------------------------------------------------
** push_swap.c
** ----------------------------------------------------------------------------
*/
void	print_status_a(t_stack *a, t_stack *b, int range, int *n_sort);
void	print_status_b(t_stack *a, t_stack *b, int range, int *n_sort);
/*
** ----------------------------------------------------------------------------
** solve_stack_rewind.c
** ----------------------------------------------------------------------------
*/
void	rewind_stack(t_stack *a, t_stack *b, int ra, int rb);
/*
** ----------------------------------------------------------------------------
** solve_a.c & solve_b.c
** ----------------------------------------------------------------------------
*/
void	solve_a(t_stack *a, t_stack *b, int range, int options);
void	solve_b(t_stack *a, t_stack *b, int range, int options);
int		case3a(t_stack *a, t_stack *b);
int		case3b(t_stack *a, t_stack *b);
int		solve_specific_case_a(t_stack *a, t_stack *b, int range);
/*
** ----------------------------------------------------------------------------
** solve_case3a.c & solve_case3b.c
** ----------------------------------------------------------------------------
*/
void	case3a_021(t_stack *a, t_stack *b);
void	case3a_201(t_stack *a, t_stack *b);
void	case3a_120(t_stack *a, t_stack *b);
void	case3a_210(t_stack *a, t_stack *b);
void	case3b_012(t_stack *a, t_stack *b);
void	case3b_021(t_stack *a, t_stack *b);
void	case3b_102(t_stack *a, t_stack *b);
void	case3b_201(t_stack *a, t_stack *b);
void	case3b_120(t_stack *a, t_stack *b);
/*
** ----------------------------------------------------------------------------
** solve_pivot.c
** ----------------------------------------------------------------------------
*/
int		find_pivot(t_stack *stack, int range);
int		find_pivot2(t_stack *stack, int range, int *pivot);
int		last_smaller_than_pivot(t_stack *stack, int range, int pivot);
int		last_larger_than_pivot(t_stack *stack, int range, int pivot);
/*
** ----------------------------------------------------------------------------
** instructionsN.c
** ----------------------------------------------------------------------------
*/
void	instruction_pa(t_stack *a, t_stack *b);
void	instruction_pb(t_stack *a, t_stack *b);
void	instruction_sa(t_stack *a, t_stack *b);
void	instruction_sb(t_stack *a, t_stack *b);
void	instruction_ss(t_stack *a, t_stack *b);
void	instruction_ra(t_stack *a, t_stack *b);
void	instruction_rb(t_stack *a, t_stack *b);
void	instruction_rr(t_stack *a, t_stack *b);
void	instruction_rra(t_stack *a, t_stack *b);
void	instruction_rrb(t_stack *a, t_stack *b);
void	instruction_rrr(t_stack *a, t_stack *b);
#endif
