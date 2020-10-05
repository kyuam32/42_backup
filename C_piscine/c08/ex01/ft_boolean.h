/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 11:36:27 by nlee              #+#    #+#             */
/*   Updated: 2020/08/19 17:26:35 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define SUCCESS 1
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"
# define EVEN even_cheack

typedef	char	t_bool;

t_bool	even_cheack(int nbr)
{
	if (nbr % 2 == 0)
		return (TRUE);
	return (FALSE);
}

#endif
