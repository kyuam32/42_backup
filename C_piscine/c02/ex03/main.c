#include <unistd.h>
 
int			ft_str_is_numeric(char *str)
{
	char	*temp;
	int		check;
	int		i;

	temp = str;
	i = 0;
	check = 1;
	while (temp[i] != '\0')
	{
		if (temp[i] < '0' || temp[i] > '9')
		{
			check = 0;
		}
		i++;
	}

	return (check);
}

int main(void)
{
	char str[] = "1123211";
	char result = '0' + ft_str_is_numeric(str);

	write(1,&result,1);
}
