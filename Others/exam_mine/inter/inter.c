#include <unistd.h>

int main(int ac, char **av)
{
	char arr[255];
	int i;

	if (ac == 3)
	{
		i = -1;
		while (++i < 255)
			arr[i] = 0;
		i = 0;
		while (av[2][i])
		{
			if (arr[(int)av[2][i]] == 0)
				arr[(int)av[2][i]] = 1;
			i++;
		}
		i = 0;
		while (av[1][i])
		{
			if (arr[(int)av[1][i]] == 1)
			{
				write(1, &av[1][i], 1);
				arr[(int)av[1][i]] = 2;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
