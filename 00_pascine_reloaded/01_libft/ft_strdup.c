#include "libft.h"
char *ft_strdup (char *s1) {
    size_t	len = ft_strlen(s1) + 1;

    char *str = malloc(len);
    if (!str) {
        return NULL;
    }
    ft_memcpy(str, s1, len);
    return (str);
}


