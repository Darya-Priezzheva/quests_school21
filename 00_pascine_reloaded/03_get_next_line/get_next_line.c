#include <stdio.h>
#include "get_next_line.h"

int get_next_line (int fd, char **line)
{
    if (fd < 0 || !line) {
        return -1;
    }
    static char *buffer = NULL;
    static int is_binary = 0;

    if (buffer == NULL && is_binary == 0) {
        is_binary = check_binary(fd);
        if (is_binary) {
            //lseek(fd, 0, SEEK_SET);
            buffer = NULL;
            return -1;
        }
    }
    if (!buffer) {
        buffer = ft_strdup("");
        if (!buffer) {
            return -1;
        }
    }
    while (!ft_strchr(buffer, '\n')) {
         int status = read_to_buffer(fd, &buffer);
         if (status == -1) {
             all_free(&buffer);
             return -1;
         }
         if (status == 0) {
             break;
         }
    }
    int result = extract_line(&buffer, line);

    if (result == -1) {
        all_free(&buffer);
    }

    return result;
}