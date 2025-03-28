#include <unistd.h>
#include "libft.h"
void ft_putstr_fd (char *s, int fd) {
    if (!s || fd < 0) {
        return;
    }

    size_t len = ft_strlen(s);
    write(fd, s, len);
}
