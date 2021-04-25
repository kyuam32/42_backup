/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minckim <minckim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:01:10 by minckim           #+#    #+#             */
/*   Updated: 2020/10/29 21:54:22 by minckim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	char	result;

	while (!(result = *s1 - *s2) && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (result);
}
