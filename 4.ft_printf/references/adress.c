#include <stdio.h>
#include <stdarg.h>

// void    check(int format, ...)
// {
//     int adress;
//     va_list ap;

//     adress = 1;
//     va_start(ap, format);
//     va_arg(ap, void *)
//     printf("[%]\n",)
// }


int main()
{
    int adress;

    adress = 1;
    // check(1, adress);
    printf("%p\n", &adress);
}