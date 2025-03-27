#include "libft.h"
void *ft_memccpy (void *dst, const void *src, int c, size_t n) {
    unsigned char *d = dst;
    const unsigned char *s = src;
    if (!dst && !src) {
        return NULL;
    }
    while (n--) {
        *d++ = *s++;
        if (*(d - 1) == (unsigned char)c) {
            return d;
        }
    }
    return NULL;
}
