/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 21:20:50 by nlee              #+#    #+#             */
/*   Updated: 2020/08/13 01:37:41 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	int result;

	result = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power != 0)
		result = nb * ft_recursive_power(nb, power - 1);
	return (result);
}
