/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:55:07 by nlee              #+#    #+#             */
/*   Updated: 2020/08/12 21:07:32 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		char_check(char *c);
int		word_check(char *c);
char	cvrt_to_cap(char *c);
char	cvrt_to_uncap(char *c);

char	*ft_strcapitalize(char *str)
{
	int i;

	if (str[0] == 0)
		return (0);
	cvrt_to_cap(&str[0]);
	write(1, &str[0], 1);
	i = 1;
	while (str[i])
	{
		word_check(&str[i]);
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}

int		char_check(char *c)
{
	if (*c >= '0' && *c <= '9')
		return (1);
	else if (*c >= 'a' && *c <= 'z')
		return (1);
	else if (*c >= 'A' && *c <= 'Z')
		return (1);
	return (0);
}

int		word_check(char *c)
{
	if (char_check(c - 1) == 0 && char_check(c + 1) == 1)
		*c = cvrt_to_cap(c);
	else if (char_check(c - 1) == 0 && char_check(c + 1) == 0)
		*c = cvrt_to_cap(c);
	else if (char_check(c - 1) == 1 && char_check(c + 1) == 0)
		*c = cvrt_to_uncap(c);
	else if (char_check(c - 1) == 1 && char_check(c + 1) == 1)
		*c = cvrt_to_uncap(c);
	return (0);
}

char	cvrt_to_cap(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
	return (*c);
}

char	cvrt_to_uncap(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
		*c += 32;
	return (*c);
}
