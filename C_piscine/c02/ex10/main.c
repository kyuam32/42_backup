/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stlcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 21:44:47 by nlee              #+#    #+#             */
/*   Updated: 2020/08/12 21:13:32 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int main ()
{
	char d[30] = "123123";
	char d2[30] = "123123";
	char s[30] = "abc";
	unsigned int i;

	i = 9;
	printf("%u\n",ft_strlcpy(d,s,i));
	printf("%lu\n",strlcpy(d2,s,i));
	printf("%s\n",d);
	printf("%s\n",d2);
}
