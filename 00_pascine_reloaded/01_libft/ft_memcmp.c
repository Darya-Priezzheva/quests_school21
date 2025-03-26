#include "libft.h"
int ft_memcmp (const void *s1, const void *s2, size_t n) {
    unsigned const char *p1 = s1;
    unsigned const char *p2 = s2;
    while (n--) {
        if (*p1 != *p2) {
            return *p1 - *p2;
        }
        p1++;
        p2++;
    }
    return 0;
}