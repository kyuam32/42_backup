#include <stdlib.h>
#include <stdio.h>

int			ft_strlen(char *src)
{
	int		i;

	i = 0;
	while (*src)
	{
		i++;
		src++;
	}
	return (i);
}

char		*ft_strdup(char *src)
{
	char	*duple;
	int		i;

	i = 0;
	duple = (char *)malloc(sizeof(char) * ft_strlen(src));
	while (src[i])
	{
		duple[i] = src[i];
		i++;
	}
	duple[i] = 0; 
	return (duple);
}

int main()
{
	char *c;

	c = "asdasdasd";

	printf("%s\n",c);
	printf("%s\n",ft_strdup(c));


}
