#include "ft_stock_str.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_show_tab(struct s_stock_str *par);
struct	s_stock_str	*ft_strs_to_tab(int ac, char **av);

int	main(void)
{
	int ac = 3;
	char **av = (char **)malloc(sizeof(char *) * ac);
	av[0] = "123456789";
	av[1] = "abcdefghij";
	av[2] = "a1s2d3f4";
	ft_show_tab(ft_strs_to_tab(ac, av));
	return (0);
}
