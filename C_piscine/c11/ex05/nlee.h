/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlee.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 11:32:14 by nlee              #+#    #+#             */
/*   Updated: 2020/08/21 12:18:34 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NLEE_H
# define NLEE_H

# include <unistd.h>

int		ft_atoi(char *str);
void	display(long long result);
void	cal_plus(int num1, int num2);
void	cal_min(int num1, int num2);
void	cal_multi(int num1, int num2);
void	cal_devied(int num1, int num2);
void	cal_remain(int num1, int num2);

#endif
