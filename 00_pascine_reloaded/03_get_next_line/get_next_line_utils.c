#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include "get_next_line.h"

char *ft_strchr (const char *str, int c) {
    while (*str) {
        if (*str == (char)c) {
            return (char *)str;
        }
        str++;
    }
    if (c == '\0') {
        return (char *)str;
    }
    return NULL;
}

size_t ft_strlen (const char *str) {
    size_t len = 0;
    while (str[len]) {
        len++;
    }
    return len;
}

size_t ft_strlcpy (char *dst, const char *src, size_t size) {
    size_t src_len = ft_strlen(src);
    size_t i = 0;
    if (size) {
        while (i < size - 1 && src[i]) {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    return src_len;
}

char *ft_strjoin (const char *s1, char const *s2) {
    char *str;
    if (!s1 || !s2) {
        return NULL;
    }
    size_t s1_len = ft_strlen(s1);
    size_t s2_len = ft_strlen(s2);
    str = (char *)malloc(sizeof(char) * s1_len + s2_len + 1);
    if (!str) {
        return NULL;
    }
    ft_memcpy(str, s1, s1_len);
    ft_memcpy(str + s1_len, s2, s2_len);
    str[s1_len + s2_len] = '\0';
    return str;
}

void *ft_memcpy (void *dst, const void *src, size_t n) {
    unsigned char *d = dst;
    const unsigned char *s = src;
    if (!dst && !src) {
        return NULL;
    }
    while (n--) {
        *d++ = *s++;
    }
    return dst;
}

char *ft_strdup (char *s1) {
    size_t	len = ft_strlen(s1) + 1;

    char *str = malloc(len);
    if (!str) {
        return NULL;
    }
    ft_memcpy(str, s1, len);
    return (str);
}


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