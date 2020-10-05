#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	ft_putstr(char *str)
{
	int temp_no;

	temp_no = 0;
	while (str[temp_no] != '\0')
	{
		ft_putchar(str[temp_no]);
		temp_no++;
	}
}

int		main()
{
	char *str;

	str = "hello world";
	ft_putstr(str);
}
