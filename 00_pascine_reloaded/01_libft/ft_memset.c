#include "libft.h"
void *ft_memset (char *str, int c, size_t len) {
    char *p = str;
    while (len--) {
        *p = (unsigned char)c;
        p++;
    }
    return str;
}