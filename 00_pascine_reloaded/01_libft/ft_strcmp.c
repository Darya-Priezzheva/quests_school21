#include <stdio.h>

int ft_strcmp (char *s1, char *s2) {
    int res = 0;
    while (*s1 == *s2 && *s1 != '\0') {
        s1++;
        s2++;
    }
    if (*s1 == '\0' && *s2 == '\0') {
        res = 0;
    } else if (*s1 > *s2) {
        res = 1;
    } else {
        res = -1;
    }

    return res;
}

int main () {
    int result = ft_strcmp("abc", "abn");
    printf("%d\n", result);

    return 0;
}
