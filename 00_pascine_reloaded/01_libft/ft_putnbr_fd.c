#include <unistd.h>
#include "libft.h"
void ft_putnbr_fd (int n, int fd) {
    if (fd < 0) {
        return;
    }
    long num = (long)n;
    char c;
    if (num < 0) {
        write(fd, "-", 1);
        num = -num;
    }
    if (num >= 10) {
        ft_putnbr_fd(num / 10, fd);
    }
    c = (num % 10) + '0';
    write(fd, &c, 1);
}