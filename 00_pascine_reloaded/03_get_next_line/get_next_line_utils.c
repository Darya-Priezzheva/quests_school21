#include "get_next_line.h"

char *ft_strchr (const char *str, int c) {
    while (*str) {
        if (*str == (char)c) {
            return (char *)str;
        }
        str++;
    }
    if (c == '\0') {
        return (char *)str;
    }
    return NULL;
}

size_t ft_strlen (const char *str) {
    size_t len = 0;
    while (str[len]) {
        len++;
    }
    return len;
}

size_t ft_strlcpy (char *dst, const char *src, size_t size) {
    size_t src_len = ft_strlen(src);
    size_t i = 0;
    if (size) {
        while (i < size - 1 && src[i]) {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    return src_len;
}

char *ft_strjoin (const char *s1, char const *s2) {
    char *str;
    if (!s1 || !s2) {
        return NULL;
    }
    size_t s1_len = ft_strlen(s1);
    size_t s2_len = ft_strlen(s2);
    str = (char *)malloc(sizeof(char) * s1_len + s2_len + 1);
    if (!str) {
        return NULL;
    }
    ft_memcpy(str, s1, s1_len);
    ft_memcpy(str + s1_len, s2, s2_len);
    str[s1_len + s2_len] = '\0';
    return str;
}

void *ft_memcpy (void *dst, const void *src, size_t n) {
    unsigned char *d = dst;
    const unsigned char *s = src;
    if (!dst && !src) {
        return NULL;
    }
    while (n--) {
        *d++ = *s++;
    }
    return dst;
}

char *ft_strdup (char *s1) {
    size_t	len = ft_strlen(s1) + 1;

    char *str = malloc(len);
    if (!str) {
        return NULL;
    }
    ft_memcpy(str, s1, len);
    return (str);
}