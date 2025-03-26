#include "libft.h"
void *ft_memcpy (void *dst, const void *src, size_t n) {
    char *d = dst;
    char *s = src;
    if (!dts && !src) {
        return NULL;
    }
    while (n--) {
        *d++ = *s++;
    }
    return dst;
}
