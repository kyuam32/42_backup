/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 08:57:57 by michoi            #+#    #+#             */
/*   Updated: 2020/07/19 20:30:52 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"
#include "../include/check_exception.h"
#include "../include/make_dict.h"
#include "../include/print_err.h"
#include "../include/split_num.h"
#include "../include/invert_to_word.h"

void		ft_free(void)
{
	int		n;

	n = 0;
	while (n < g_max_dict)
	{
		free(g_dict[n].str);
		free(g_dict[n].key);
		free(g_dict[n].value);
		n++;
	}
	free(g_dict);
	n = 0;
	while (n < g_max_num + 2)
	{
		free(g_num[n]);
		n++;
	}
	free(g_num);
}

int			main(int argc, char *argv[])
{
	char	*dict_name;
	int		i;

	i = 0;
	dict_name = check_exception(argc, argv);
	if (dict_name == 0)
		return (print_err());
	if (split_num(argc, argv))
		return (print_alloc_err());
	if (make_dict(dict_name))
		return (print_dict_err());
	invert_to_word();
	ft_free();
	return (0);
}
