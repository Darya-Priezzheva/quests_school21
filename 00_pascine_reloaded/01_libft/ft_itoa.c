#include "libft.h"

static int get_len (int n) {
    int len = 1;
    if (n < 0) {
        len++;
    }
    while (n / 10 != 0) {
        len++;
        n/= 10;
    }
    return len;
}

char *ft_itoa (int n) {
    char *str;
    int len;
    int negative;
    long num;
    num = (long)n;
    len = get_len(n);
    str = (char *)malloc(sizeof(char *) * (len + 1));
    if (!str) {
        return NULL;
    }
    str[len] = '\0';
    negative = (num < 0);
    if (negative) {
        str[0] = '-';
        num = -num;
    }
    else if (n == 0) {
        str[0] = '0';
    }
    while (num != 0) {
        str[len] = (num % 10) + '0';
        n /= 10;
        len--;
    }
    return str;
}
