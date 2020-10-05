#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


int	ft_strlen(char *str)
{
	int temp_no;
	int count_str;

	count_str = 0;
	temp_no = 0;
	while (str[temp_no] != '\0')
	{
		count_str++;
		temp_no++;
	}
	return count_str;
}

int		main()
{
	char str[] = "hello world";
	char result;

	result = ft_strlen(str);

	printf("%d\n",result);
}
