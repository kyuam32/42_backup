#include "libft.h"

void	*memmove(void *dst, const void *src, size_t n)
{
	unsigned long dst_ptr;
    unsigned long src_ptr;
    unsigned char temp;

	dst_ptr = (long)dst;
	src_ptr = (long)src;
	if (dst_ptr <= src_ptr) {
        while (n > 0) {
            temp = ((unsigned char *) src_ptr)[0];
            ((unsigned char *) dst_ptr)[0] = temp;
            dst_ptr++;
            src_ptr++;
            n--;
        }
    }
	return (dst);
}
