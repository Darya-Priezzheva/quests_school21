#include "libft.h"
void *ft_calloc (size_t num, size_t size) {
    void *ptr;
    size_t total = num * size;
    if (size && total / size != num) {
        return NULL;
    }
    ptr = malloc(total);
    if (!ptr) {
        return NULL;
    }
    ft_bzero(ptr, total);
    return ptr;
}