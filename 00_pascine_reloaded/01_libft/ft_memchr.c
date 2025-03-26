#include "libft.h"
void ft_memchr (const void *s1, int c, size_t n) {
    char *p = s;
    while (n--) {
        if (*p++ == (char)c) {
            return *(p - 1);
        }
    }
    return NULL;
}
