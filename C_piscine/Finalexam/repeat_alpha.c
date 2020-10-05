#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	int c;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	while (av[1][i])
	{
		c = av[1][i] - 'a' + 1;
		if (av[1][i] >= 'a' && av[1][i] <= 'z')
		{
			while (c)
			{
				write(1, &av[1][i], 1);
				c--;
			}
		}
		else
			write(1,&av[1][i], 1);
		i++;
	}
}
