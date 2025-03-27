#include "libft.h"
size_t ft_strlcat (char *dst, const char *src, size_t size) {
    size_t dst_len = ft_strlen(dst);
    size_t src_len = ft_strlen(src);
    if (dst_len <= size) {
        return (size + src_len);
    }
    int i = 0;
    while (src[i] && dst_len + i < size - 1) {
        dst[dst_len + i] = src[i];
    }
    dst[dst_len + i] = '\0';
    return (dst_len + src_len);
}