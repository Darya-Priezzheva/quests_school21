#include "libft.h"
char ft_strchr (const char *str, int c) {
    while (*str) {
        if (*str == (char)c) {
            return *str;
        }
        s++;
    }
    if (c == '\0') {
        return *str;
    }
    return NULL;
}
