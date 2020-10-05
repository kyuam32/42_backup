#include <unistd.h>
int		ft_str_is_printable(char *str)
{
	char *temp;
	int check;
	int i;

	temp = str;
	i = 0;
	check = 1;
	while (temp[i] != '\0')
	{
		if (temp[i] < 32 || temp[i] > 126)
		{
			check = 0;
		}
		i++;
	}
	return check;
}

int main(void)
{
	char str[] = "ewqewq";
	char result = '0' + ft_str_is_printable(str);

	write(1,&result,1);
}
