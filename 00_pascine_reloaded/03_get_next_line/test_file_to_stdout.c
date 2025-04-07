#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int main() {
    int fd = open("test2.txt", O_RDONLY);
    if (fd == -1) {
        write(2, "File error\n", 11);
        return 1;
    }

    char *line;

    while (get_next_line(fd, &line) > 0) {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return 0;
}
