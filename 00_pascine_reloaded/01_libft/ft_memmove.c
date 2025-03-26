#include "libft.h"
void *ft_memmove (void *dst, const void *src, size_t len) {
    char *d = dst;
    char *s = src;
    if (d == s || len == 0) {
        return dst;
    }
    if (d < s) {
        while (len--) {
            *d++ = *s++;
        }
    } else {
        d += len;
        s += len;
        while (len--) {
            *--d = *--s;
        }
    }
    return dst;

}
