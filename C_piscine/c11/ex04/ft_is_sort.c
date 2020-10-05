/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 09:04:27 by nlee              #+#    #+#             */
/*   Updated: 2020/08/21 11:00:54 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int ascend;
	int descend;

	i = 0;
	ascend = 0;
	descend = 0;
	if (length < 2)
		return (1);
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) >= 0)
			ascend++;
		if (f(tab[i], tab[i + 1]) <= 0)
			descend++;
		i++;
	}
	if (ascend == length - 1 || descend == length - 1)
		return (1);
	return (0);
}
