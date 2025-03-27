#include "libft.h"
void *ft_memchr (const void *s, int c, size_t n) {
    const unsigned char *p = s;
    while (n--) {
        if (*p++ == (char)c) {
            return ((void *)(p - 1));
        }
    }
    return NULL;
}
