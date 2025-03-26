#include "libft.h"
void *ft_memccpy (void *dst, const void *src, int c, size_t n) {
    char *d = dst;
    char *s = src;
    if (!dts && !src) {
        return NULL;
    }
    while (n--) {
        *d++ = *s++;
        if (*(dst - 1) == (unsigned char)c) {
            return d;
        }
    }
    return NULL;
}
