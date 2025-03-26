#include "libft.h"
int ft_strlen (char *str) {
    size_t len = 0;
    while (str[len]) {
        len++;
    }
    return len;
}