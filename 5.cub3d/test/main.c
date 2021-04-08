#include <stdio.h>
#include "../1.libft/libft.h"

// int main(int argc, char **argv)
// {
// 	int i = 0;
// 	while (i < argc)
// 	{
// 		if (ft_memcmp((argv[1] + (ft_strlen(argv[1]) - 4)), ".cub", 4) != 0)
// 			printf("ERR\n");
// 		printf("argv[%d] = %s\n", i, argv[i]);
// 		printf("argc = %d , i = %d\n", argc, i);
// 		i++;
// 	}
// }

static void
	set_int_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

int main()
{
	int				temp;
	unsigned char	bmpfileheader[4];


	temp = 0b00001111000001110000001100000001;
	bmpfileheader[0] = 0;
	bmpfileheader[1] = 0;
	bmpfileheader[2] = 0;
	bmpfileheader[3] = 0;

	set_int_in_char(bmpfileheader, temp);

	printf("1 : %d\n", bmpfileheader[0]);
	printf("2 : %d\n", bmpfileheader[1]);
	printf("3 : %d\n", bmpfileheader[2]);
	printf("4 : %d\n", bmpfileheader[3]);
}
