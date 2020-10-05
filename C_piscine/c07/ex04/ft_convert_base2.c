/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 21:38:46 by nlee              #+#    #+#             */
/*   Updated: 2020/08/16 23:04:09 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			base_check(char *bs, char *s)
{
	int i;

	i = 0;
	while (bs[i])
	{
		if (bs[i] == *s)
			return (1);
		i++;
	}
	return (0);
}

int			str_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		base_change(char *str, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (*str == base[i])
			return (i);
		i++;
	}
	return (0);
}
