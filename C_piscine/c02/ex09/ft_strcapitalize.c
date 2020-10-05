/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 14:13:54 by nlee              #+#    #+#             */
/*   Updated: 2020/08/13 14:13:58 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_first(char *str, int index)
{
	int i;

	i = index - 1;
	if (index == 0)
		return (1);
	if (str[i] >= '0' && str[i] <= '9')
		return (0);
	if (str[i] >= 'A' && str[i] <= 'Z')
		return (0);
	if (str[i] >= 'a' && str[i] <= 'z')
		return (0);
	return (1);
}

void	change_upcase(char *str, int index)
{
	if (str[index] >= 'a' && str[index] <= 'z')
		str[index] = str[index] - 32;
}

void	change_lowcase(char *str, int index)
{
	if (str[index] >= 'A' && str[index] <= 'Z')
		str[index] = str[index] + 32;
}

char	*ft_strcapitalize(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		if (is_first(str, index))
			change_upcase(str, index);
		else
			change_lowcase(str, index);
		index++;
	}
	return (str);
}
