#include "get_next_line.h"
#include <stdio.h>
int main() {
    int fd = 0;

    char *line;

    while (get_next_line(fd, &line) > 0) {
        printf("%s\n", line);
        free(line);
    }

    return 0;
}