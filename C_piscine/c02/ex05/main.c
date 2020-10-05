#include <unistd.h>

int		ft_str_is_uppercase(char *str)
{
	char *temp;
	int check;
	int i;

	temp = str;
	i = 0;
	check = 1;
	while (temp[i] != '\0')
	{
		if (temp[i] < 'A' || temp[i] > 'Z')
		{
			check = 0;
		}
		i++;
	}

	return check;
}

int main(void)
{
	char str[] = "";
	char result = '0' + ft_str_is_uppercase(str);

	write(1,&result,1);
}
