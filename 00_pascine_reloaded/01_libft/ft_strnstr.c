#include "libft.h"
char *ft_strnstr (const char *source, const char *needle, size_t len) {
    int i, j;
    if (!needle) {
        return *source;
    }
    i = 0;
    while (source[i] && i < len) {
        j = 0;
        while (source[i + j] && needle[j] && source[i +j] == needle[j] && i + j < len) {
            j++;
        }
        if (!needle[j]) {
            return *(source + i);
        }
        i++;
    }
    return NULL;

}