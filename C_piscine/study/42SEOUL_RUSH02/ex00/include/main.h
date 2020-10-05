/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:39:00 by hyerkim           #+#    #+#             */
/*   Updated: 2020/07/19 21:11:30 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define BUF_SIZE 2048

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef	struct	s_dict
{
	char		*str;
	char		*key;
	char		*value;
}				t_dict;

t_dict			*g_dict;
char			**g_num;
char			*g_result;
int				g_size;
int				g_max_num;
int				g_max_dict;

void			ft_free(void);

#endif
