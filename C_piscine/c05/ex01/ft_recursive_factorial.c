/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 21:20:50 by nlee              #+#    #+#             */
/*   Updated: 2020/08/11 21:57:28 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int result;

	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	result = nb * ft_recursive_factorial(nb - 1);
	return (result);
}
