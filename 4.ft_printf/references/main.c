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

#define _FLAG_
// - , 0

int main()
{
    char c;
    const char *str = "HELLO EVERYONE";

    c = 0;
    //printf("[%c]\n", str);
    write(1, str, 1);
    str++;
    write(1, str, 1);
    str++;
    write(1, str, 1);
    str++;
    write(1, str, 1);
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