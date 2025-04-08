#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
int main() {

    int fd1 = open("test1.txt", O_RDONLY);
    int fd2 = open("test2.txt", O_RDONLY);
    int fd3 = open("test3.txt", O_RDONLY);

    char *line;

    get_next_line(fd1, &line);
    printf("fd1: %s\n", line);
    free(line);

    get_next_line(fd2, &line);
    printf("fd2: %s\n", line);
    free(line);

    get_next_line(fd1, &line);
    printf("fd1: %s\n", line);
    free(line);

    get_next_line(fd3, &line);
    printf("fd3: %s\n", line);
    free(line);


    close(fd1);
    close(fd2);
    close(fd3);

    return 0;
}
