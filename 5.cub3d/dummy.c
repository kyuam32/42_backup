
// void map_sizecheck(t_data *data)
// {
// 	int i;
// 	int row;
// 	int col;
// 	int checker;

// 	row = 0;
// 	col = 0;
// 	i = 0;
// 	while (data->map.map_str[i])
// 	{
// 		if (data->map.map_str[i] == '\n')
// 			row++;
// 		i++;
// 	}
// 	i = 0;
// 	checker = 0;
// 	while (data->map.map_str[i])
// 	{
// 		if (data->map.map_str[i] == '\n')
// 		{
// 			if (checker && checker != col)
// 				data->crash_report = MAP_DATA_CORRUPTED;
// 			checker = col;
// 			if (data->map.map_str[i + 1] != 0)
// 				col = -1;
// 		}
// 		i++;
// 		col++;
// 	}
// 	col--;

// 	data->map.col = col;
// 	data->map.row = row;
// }

// void map_interval_check(t_data * data)
// {
// 	int i;
// 	int j;

// 	if (ft_isdigit(data->map.map_str[1]))
// 		data->map.interval = 1;
// 	else if(data->map.map_str[1] == ' ' && ft_isdigit(data->map.map_str[2]))
// 	{
// 		data->map.interval = 2;
// 		data->map.col = data->map.col / 2 + 1;
// 	}
// 	else
// 		data->crash_report = MAP_DATA_CORRUPTED;
// 	i = 0;
// 	while (data->map.map_str[i])
// 	{
// 		if (is_valid_char(data->map.map_str[i]))
// 		{
// 			j = 1;
// 			while (!(is_valid_char(data->map.map_str[i + j])) && data->map.map_str[i + j] != 0 && data->map.map_str[i + j] != '\n')
// 				j++;
// 			if (is_valid_char(data->map.map_str[i + j]) && data->map.interval != j)
// 				data->crash_report = MAP_DATA_CORRUPTED;
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while (data->map.map_str[i] && data->map.interval == 2)
// 	{
// 		if ((data->map.map_str[i]) == ' ')
// 		{
// 			j = data->map.interval;
// 			if ((data->map.map_str[i + j]) == ' ' || (data->map.map_str[i + j]) == 0 || (data->map.map_str[i + j]) == '\n')
// 				i++;
// 			else
// 				data->crash_report = MAP_DATA_CORRUPTED;
// 		}
// 	}
// }


	t_minimap *map;
	int c;
	int i;
	int j;

	map = &data->map;
	c = 0;
	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			if (map->map_str[c] == '\n')
				c++;
			if (is_valid_char(map->map_str[c]))
				map->map_array[i][j] = map->map_str[c] - '0';
			else if (map->map_str[c] == ' ')
				map->map_array[i][j] = 1;
			j++;
			c += map->interval;
		}
		i++;
	}