#include "libft.h"
int ft_atoi (const char *str) {
    int sign = 1;
    long result = 0;
    while (*str == ' ' || (*str >= '\t' && *str <= '\r')) {
        str++;
    }
    if (*str == '-' || *str == '+') {
        if (*str == '-') {
            sign *= -1;
        }
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    result *= sign;
    return result;
}
