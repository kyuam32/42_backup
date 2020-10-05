#include <unistd.h>

char		*ft_strcat(char *dest, char *src)
{
	char	*d;
	char	*s;

	d = dest;
	s = src;
	while (*d)
		d++;
	while (*s)
	{
		*d = *s;
		d++;
		s++;
	}
	*d = 0;
	return (dest);
}
