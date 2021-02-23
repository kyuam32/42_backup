#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

// void    myprintf(char *arg_num, ...)
// {
//     va_list ap;
//     int     i;
//     int     temp;

//     va_start(ap, arg_num);
//     for (i = 0; (temp = va_arg(ap, int)) != 0; i++)
//     {
//         printf("%c\n",temp);
//         printf("ap = %p\n", ap);
//     }
//     printf("%s\n",arg_num);
//     va_end(ap);
// }

// int		init_write(unsigned long long num, int base, char *base_str)
// {
// 	int i;

// 	i = 0;
// 	if (n >= base)
// 	{
// 		i++;
// 		i += init_write(n / base, base);
// 	}
// 	write(1, &base_str[n % base], 1);
// 	return (i);
// }

// void    ft_temp(long long n)
// {
//     printf("%lld", n);
// }

// void    test(char *form, ...)
// {
//     va_list ap;
//     long long num;

//     va_start(ap, form);
//     num = (long long)va_arg(ap, void *);
//     printf("test : [%llx]\n", num);
// }


int main()
{
    long long num;
    int *temp;

    temp = 0;

    printf("printf : [% *.5i]", 4, 42);
    // int *n;
    // test("hi", n);
    // unsigned long long num = 12345;
    // char *str = "0123456789";

    // ft_temp(n);
    // printf("STRLEN %init_write(num, base, str)
    // printf("%p\n%p\n%p\n", n, c, lld);
    // printf("[%l]\n[%l]\n", LONG_MIN, LgONG_MAX);
    // printf("[%ll]\n[%ll]\n", __LONG_LONG_MAX__, LONG_LONG_MIN);
    //printf("%010.*i\n",-2, 24);
    //printf("%010.*u\n",-3, 24);
    //printf("%010.*x\n",-4, 24);
    //printf("%010.*X\n",-5, 24);
    //printf("%010.*%\n", -5);g
    //printf("%.c\n", 'A');
    //printf("%-10.2s\n", "STRABC");
    //printf("%.4p\n", sum);
    //printf("%o",);
    //printf("%e",);
    //printf("%E",);
    //printf("%f",);
    //printf("%F",);
    //printf("%g",);
    //printf("%G",);
    //printf("%a",);
    //printf("%A",);
    //printf("%n",);
}