#include "libft.h"
char *ft_strmapi (const char *s, char (*f)(unsigned int, char)) {
    char *new_s;
    size_t len;
    size_t i;

    if (!s || !f) {
        return NULL;
    }

    len = ft_strlen(s);
    new_s = (char *)malloc(sizeof(char *) * (len + 1));
    if (!new_s) {
        return NULL;
    }
    i = 0;
    while (i < len) {
        new_s[i] = f(i, s[i]);
        i++;
    }
    new_s[len] = '\0';

    return new_s;
}
