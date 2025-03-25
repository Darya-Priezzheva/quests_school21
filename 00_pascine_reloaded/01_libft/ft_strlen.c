#include <stdio.h>

int ft_strlen (char *str) {
    if (!str) {
        return 0;
    }
    int count = 0;
    char *ptr = str;
    while (*ptr != '\0') {
        count++;
        ptr++;
    }
    return count;
}

int main () {
    char str[] = "hello, school";
    printf("%d", ft_strlen(str));

    return 0;
}