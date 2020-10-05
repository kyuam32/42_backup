#include <stdio.h>

char **ft_split(char *str, char *charset);

int main(void)
{
	char str[500] = "";
//	char str[500] = "  \t ";
//	char charset[500] = " \t";
	char charset[500] = "";
	char **result = ft_split(str, charset);
	printf("%s\n%s\n--------------\n", str, charset);
	for(int i = 0; result[i]; i++)
		printf("%s\n", result[i]);

	return 0;
}
