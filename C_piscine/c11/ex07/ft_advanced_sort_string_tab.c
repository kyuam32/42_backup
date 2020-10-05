/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 12:44:39 by nlee              #+#    #+#             */
/*   Updated: 2020/08/21 15:14:31 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void		ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int i;
	int j;
	int len;

	len = 0;
	while (tab[len])
		len++;
	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1 - i)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
				str_swap(tab, j, j + 1);
			j++;
		}
		i++;
	}
}
