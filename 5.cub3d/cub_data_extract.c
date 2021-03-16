/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_data_extract.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:09:09 by namkyu            #+#    #+#             */
/*   Updated: 2021/03/09 16:19:03 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void rgb_parse(char *str, int *object, t_data *data)
{
	int temp;
	int bit;

	bit = 16;
	*object = 0; // 난중에 초기화 함수 넣고 지워라
	while (*str == ' ')
		str++;
	while (ft_isdigit(*str) || *str == ',')
	{
		if (*str == ',')
			str++;
		if ((temp = ft_atoi(str)) > 255 || temp < 0)
			data->crash_report = CUB_DATA_CORRUPTED;
		else
		{
			*object += temp << bit;
			bit -= 8;
		}
		while (ft_isdigit(*str))
			str++;
	}
	if (bit != 0)
		data->crash_report = CUB_DATA_CORRUPTED;

	printf("[FLOOR R]%i\n", *object);
}

void resolution_parse(char *str, t_data *data)
{
	int temp;

	while(!(ft_isdigit(*str)))
		str++;
		if ((temp = ft_atoi(str)) <= 0)
			data->crash_report = CUB_DATA_CORRUPTED;
	data->resolution_width = temp;
	while(ft_isdigit(*str))
		str++;
	while(!(ft_isdigit(*str)))
		str++;
	if ((temp = ft_atoi(str)) <= 0)
		data->crash_report = CUB_DATA_CORRUPTED;
	data->resolution_height = temp;

	printf("[res 0]%d\n", data->resolution_width);
	printf("[res 1]%d\n", data->resolution_height);
}

void texture_path_parse(char *str, char *path, t_data *data)
{
	int i ;

	i = 0;
	while (*str == ' ')
		str++;
	while (str[i])
		i++;
	if (ft_memcmp((str + (i - 4)), ".xpm", 4) != 0)
		data->crash_report = CUB_DATA_CORRUPTED;
	else
		path = ft_strdup(str);


	printf("[path]%s\n", path);
}

void cub_data_sort(char *line, t_data *data)
{

	if (line[0] == 'R' && line[1] == ' ')
		resolution_parse(line, data);
	else if (line[0] == 'N' && line[1] == 'O')
		texture_path_parse(line + 2, data->texture.NO_path, data);
	else if (line[0] == 'S' && line[1] == 'O')
		texture_path_parse(line + 2, data->texture.SO_path, data);
	else if (line[0] == 'W' && line[1] == 'E')
		texture_path_parse(line + 2, data->texture.WE_path, data);
	else if (line[0] == 'E' && line[1] == 'A')
		texture_path_parse(line + 2, data->texture.EA_path, data);
	else if (line[0] == 'S' && line[1] == ' ')
		texture_path_parse(line + 1, data->texture.Sprite_path, data);
	else if (line[0] == 'F' && line[1] == ' ')
		rgb_parse(line + 1, &data->texture.floor, data);
	else if (line[0] == 'C' && line[1] == ' ')
		rgb_parse(line + 1, &data->texture.ceiling, data);
}


void cub_data_trim(t_data *data)
{
	int fd;
	char *line;
	if ((fd = open("./map.cub", O_RDONLY)) < 0)
		data->crash_report = CUB_DATA_CORRUPTED;
	while(get_next_line(fd, &line))
	{
		cub_data_sort(line, data);
		free(line);
	}
}