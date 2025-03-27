#include "libft.h"
char *ft_strrchr (const char *str, int num) {
    char c = (char)num;
    while (*str) {
        str++;
    }
    while (*str != c) {
        str--;
    }
    return (char *)str;
}
