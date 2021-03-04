#include "cub3d.h"

int main()
{
	int fd;
	char *line;
	fd = open("./map.cub", O_RDONLY);
	while(get_next_line(fd, &line))
	{
		printf("[  %s  ]\n", line);
		free(line);
	}
}