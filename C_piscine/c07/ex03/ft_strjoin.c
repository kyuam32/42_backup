#include <stdlib.h>

int             ft_strlen(char *str)
{
        int cnt;

        cnt = 0;
        while (*str != '\0')
        {
                cnt++;
                str++;
        }
        return (cnt);
}

int             ft_strcat(char *dest, char *src, int index)
{
        int i;

        i = 0;
        while (src[i] != '\0')
        {
                dest[index + i] = src[i];
                i++;
        }
        return (index + i);
}

void    ft_fill(int size, char **strs, char *sep, char *result)
{
        int i;
        int curr;

        i = 0;
        curr = 0;
        while (i < (size - 1))
        {
                curr = ft_strcat(result, strs[i], curr);
                curr = ft_strcat(result, sep, curr);
                i++;
        }
        curr = ft_strcat(result, strs[i], curr);
        result[curr] = '\0';
}

char    *ft_strjoin(int size, char **strs, char *sep)
{
        char    *result;
        int             len;
        int             i;

        len = 0;
        i = 0;
        while (i < size)
        {
                len += ft_strlen(strs[i]);
                i++;
        }
        len += (ft_strlen(sep) * (size - 1));
        if ((result = (char *)malloc(sizeof(char) * len + 1)) == NULL)
                return (0);
        ft_fill(size, strs, sep, result);
        return (result);
}
