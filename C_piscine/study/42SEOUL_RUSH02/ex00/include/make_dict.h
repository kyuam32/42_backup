/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_dict.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:37:54 by hyerkim           #+#    #+#             */
/*   Updated: 2020/07/19 20:56:18 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_DICT_H
# define MAKE_DICT_H

int		open_dict(char *dict_name, char *buf);
int		allocate_dict(int max_row);
int		split_in_line(int index);
int		split_dict(char *buf);
int		make_dict(char *dict_name);

#endif
