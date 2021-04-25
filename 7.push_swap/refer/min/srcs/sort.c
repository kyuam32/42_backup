/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:11:03 by minckim           #+#    #+#             */
/*   Updated: 2021/03/09 04:10:33 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void		swap_int(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int			*sort_by_pivot(int *left, int *right, int pivot)
{
	while (right != left)
	{
		if (pivot < *left)
		{
			while (right != left)
			{
				--right;
				if (*right < pivot)
				{
					swap_int(left, right);
					break ;
				}
			}
		}
		if (right != left)
			++left;
	}
	return (left);
}

void		quick_sort(int *begin, int *end)
{
	int		pivot;
	int		*left;

	if (end == begin)
		return ;
	if (--end == begin)
		return ;
	pivot = *end;
	left = sort_by_pivot(begin, end, pivot);
	swap_int(left, end);
	quick_sort(begin, left);
	quick_sort(++left, ++end);
}
