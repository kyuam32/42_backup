/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:54:33 by namkyu            #+#    #+#             */
/*   Updated: 2021/04/09 19:15:28 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*remove_space(char *str)
{
	char	*ret;
	int		i;
	int		space;

	i = 0;
	space = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			space++;
	}
	ret = (char *)malloc(sizeof(char) * (i - space + 1));
	ret[i - space + 1] = 0;
	i = 0;
	while (*str)
	{
		if (*str != ' ')
			ret[i] = *str;
		str++;
		i++;
	}
	return (ret);
}

void	ft_free(void *target)
{
	if (target != NULL)
		free(target);
	target = NULL;
}

void	v_iput(t_vector *vec, int x_input, int y_input)
{
	vec->x = (double)x_input;
	vec->y = (double)y_input;
}

void	v_dput(t_vector *vec, double x_input, double y_input)
{
	vec->x = x_input;
	vec->y = y_input;
}

void	player_dir_set(t_data *data, char c, int row, int col)
{
	if (data->player.locate == 0)
	{
		data->player.locate = c;
		if (c == 'E')
			v_iput(&data->player.dir, 1, 0);
		else if (c == 'W')
			v_iput(&data->player.dir, -1, 0);
		else if (c == 'S')
			v_iput(&data->player.dir, 0, 1);
		else if (c == 'N')
			v_iput(&data->player.dir, 0, -1);
		data->player.axis.x = col + 0.5;
		data->player.axis.y = row + 0.5;
	}
	else
		exit_process(data, MAP_DATA_CORRUPTED + 3);
}
