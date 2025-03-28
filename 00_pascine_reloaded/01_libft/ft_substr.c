#include "libft.h"
char *ft_substr (const char *s, unsigned int start, size_t len) {
    char *sub;
    size_t s_len = ft_strlen(s);
    if (start >= s_len) {
        return ft_strdup("");
    }
    if (len > s_len - start) {
        len = s_len - start;
    }
    sub = (char *)malloc(len + 1);
    if (!sub) {
        return NULL;
    }
    ft_memcpy(sub, s + start, len);
    sub[len] = '\0';
    return sub;
}
