#include <stdio.h>
#include <stdlib.h>

char *ft_strdup (char *src) {
    int len = 0;
    int i = 0;
    while (src[len]) {
        len++;
    }
    char *dest = malloc(sizeof(char) * (len + 1));
    while (i < len) {
        dest[i] = src[i];
        i++;
    }
    dest[len] = '\0';
    return dest;
}

int main (void) {
    char *origin = "Hello";
    char *dubl = ft_strdup(origin);

    return 0;
}

