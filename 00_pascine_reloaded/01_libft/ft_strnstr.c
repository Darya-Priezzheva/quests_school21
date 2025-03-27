#include "libft.h"
char *ft_strnstr (const char *source, const char *needle, size_t len) {
    size_t i, j;
    if (!needle) {
        return (char*)source;
    }
    i = 0;
    while (source[i] && i < len) {
        j = 0;
        while (source[i + j] && needle[j] && source[i +j] == needle[j] && i + j < len) {
            j++;
        }
        if (!needle[j]) {
            return (char *)source + i;
        }
        i++;
    }
    return NULL;

}