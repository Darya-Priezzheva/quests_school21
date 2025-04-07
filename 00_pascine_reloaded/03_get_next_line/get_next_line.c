#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

#include "get_next_line.h"


int read_to_buffer (int fd, char **buffer)
{
    char *temp_buf = malloc(BUFFER_SIZE + 1);
    if (!temp_buf) {
        return -1;
    }
    ssize_t byte_read;
    byte_read = read(fd, temp_buf, BUFFER_SIZE);
    if (byte_read <= 0) {
        free(temp_buf);
        return byte_read;
    }
    temp_buf[byte_read] = '\0';

    char *new_buf;
    if (*buffer) {
        new_buf = ft_strjoin(*buffer, temp_buf);
    } else {
        new_buf = ft_strdup(temp_buf);
    }

    free(temp_buf);
    if (!new_buf) {
        return -1;
    }
    free(*buffer);
    *buffer = new_buf;

    return byte_read;
}

int extract_line (char **buffer, char **line)
{
    char *pos = ft_strchr(*buffer, '\n');
    if (pos) {
        int len = pos - *buffer;

        *line = ft_strdup(*buffer);
        if (!*line) {
            return -1;
        }
        (*line)[len] = '\0';
        //printf("%s\n", *line);
        char *temp = ft_strdup(pos + 1);
        if (!temp) {
            free(*line);
            return -1;
        }

        free(*buffer);
        *buffer = temp;

        return 1;
    }
    else {
        if (ft_strlen(*buffer) > 0) {
            *line = ft_strdup(*buffer);
            if (!*line) {
                return -1;
            }
            free(*buffer);
            *buffer = NULL;
            return 1;
        } else {
            *line = NULL;
            return 0;
        }
    }

}

void all_free (char **buffer)
{
    if (*buffer) {
        free(*buffer);
        *buffer = NULL;
    }
}

int check_binary (int fd)
{
    unsigned char buf[512];
    off_t pos = lseek(fd, 0, SEEK_CUR);
    if (pos == -1) {
        return 1;
    }
    ssize_t bytes = read(fd, buf, sizeof(buf));

    for (ssize_t i = 0; i < bytes; i++) {
        if (buf[i] == 0 || buf[i] > 127) {
            lseek(fd, pos, SEEK_CUR);
            return 1;
        }
    }
    lseek(fd, pos, SEEK_SET);
    return 0;
}

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
            lseek(fd, 0, SEEK_SET);
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