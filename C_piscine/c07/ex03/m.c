#include <stdio.h>

char    *ft_strjoin(int size, char **strs, char *sep);

int main(void)
{
    char *strs[3] = {
        "abc",
		"DEF",
		"DEF"
    };
    char sep[] = "!+";
    char *result = ft_strjoin(0, strs, sep);
    printf("%p\n%s\n", result, result);
    return 0;
}
