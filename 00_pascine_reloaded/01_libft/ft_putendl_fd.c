#include <unistd.h>
#include "libft.h"
void ft_putendl_fd (char *s, int fd) {
    if (!s || fd < 0) {
        return;
    }
    ft_putstr_fd(s, fd);
    ft_putchar_fd('\n', fd);
}
