#include "libft.h"
int ft_strlcpy (char *dst, const char *src, size_t size) {
    size_t src_len = ft_strlen(src);
    size_t i = 0;
    if (size) {
        while (i < size - 1 && src[i]) {
            dst[i] = src[i];
            i++
        }
        dst[i] = '\0';
    }
    return src_len;
}