#include "libft.h"
void *ft_calloc (size_t num, size_t size) {
    char *ptr;
    size_r total = num * size;
    if (size && total / size != num) {
        return NULL;
    }
    if (!ptr) {
        return NULL;
    }
    ft_bzero(ptr, total);
    return ptr;
}