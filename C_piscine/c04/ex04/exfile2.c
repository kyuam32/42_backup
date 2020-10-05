#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

void	recursive_print(long nb, char *base)
{
	if (nb != 0)
	{
		recursive_print(nb / ft_strlen(base), base);
		write(1, &base[nb % ft_strlen(base)], 1);
	}
}

int		pn_check(char *base)
{
	while (*base)
	{
		if (*base == '+' || *base == '-')
			return (0);
		base++;
	}
	return (1);
}

int		duple_check(char *base)
{
	int i;

	while (*base)
	{
		i = 0;
		while (base[i + 1])
		{
			if (*base == base[i + 1])
				return (0);
			i++;
		}
		base++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long nb;

	nb = nbr;
	if ((ft_strlen(base) > 1) && duple_check(base) && pn_check(base))
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = nb * -1;
		}
		recursive_print(nb, base);
	}
}

int		main(int argc, char **argv)
{
	int n;

	n = -123424;
	if (argc == 2)
		ft_putnbr_base(n, &argv[1][0]);
	return (0);
}
