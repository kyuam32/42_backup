#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int ft_straddback(char *line, char c)
{
	char *new;
	int	i = 0;

	if (line == 0 && c == '\n')
	{
		if(!(line = (char *)malloc(1)))
			return (-1);
		*line = 0;
	}
	else if (line == 0)
	{
		if(!(new = (char *)malloc(sizeof(char) * 2)))
			return (-1);
		new[0] = c;
		new[1] = 0;
		line = new;
	}
	else
	{
		if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(line) + 2))))
			return (-1);
		while (line[i])
		{
			new[i] = line[i];
			i++;
		}
		new[i] = c;
		new[i + 1] = 0;
		free(line);
		line = new;
	}
	return (1);
}

int get_next_line(char **line)
{
	char		buff[1];
	int 		len;

	while ((len = read(0, buff, 1)) > 0)
	{
//		printf("%c", *buff);
		if (*buff == '\n')
			return (1);
		else
			ft_straddback(*line, *buff);
	}
	ft_straddback(*line, *buff);
	return (0);
}