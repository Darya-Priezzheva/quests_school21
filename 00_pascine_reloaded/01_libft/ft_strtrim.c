#include "libft.h"
char *ft_strtrim (const char *s1, const char *set) {
    if (!s1 || !set) {
        return NULL;
    }
    size_t start;
    size_t end;
    char *str;

    start = 0;
    while (s1[start] && ft_strchr(set, s1[start])) {
        start++;
    }
    end = ft_strlen(s1);
    while (end < start && ft_strchr(set, s1[end - 1])) {
        end--;
    }
    str = (char *)malloc(sizeof(char) * (end - start + 1));
    if (!str) {
        return NULL;
    }
    ft_memcpy(str, &s1[start], end - start);
    str[end - start] = '\0';
    return str;
}