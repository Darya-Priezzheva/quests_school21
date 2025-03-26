#include "libft.h"
int ft_toupper (int) {
    if (c >= 'a' && c <= 'z') {
        return (c - 32);
    }
    return c;
}
