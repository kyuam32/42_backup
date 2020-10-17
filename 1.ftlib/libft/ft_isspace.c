/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:29:25 by nlee              #+#    #+#             */
/*   Updated: 2020/10/14 15:34:33 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	if ((unsigned char)c == '\t')
		return (1);
	else if ((unsigned char)c == '\n')
		return (1);
	else if ((unsigned char)c == '\v')
		return (1);
	else if ((unsigned char)c == '\f')
		return (1);
	else if ((unsigned char)c == '\r')
		return (1);
	else if ((unsigned char)c == ' ')
		return (1);
	return (0);
}
