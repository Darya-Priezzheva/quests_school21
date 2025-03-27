#include "libft.h"
void *ft_memcpy (void *dst, const void *src, size_t n) {
    unsigned char *d = dst;
    const unsigned char *s = src;
    if (!dst && !src) {
        return NULL;
    }
    while (n--) {
        *d++ = *s++;
    }
    return dst;
}
