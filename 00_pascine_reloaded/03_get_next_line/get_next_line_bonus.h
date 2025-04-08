#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

typedef struct s_fdnode {
    int fd;
    char *buf;
    int is_binary;
    struct s_fdnode *next;
} t_fdnode;

int get_next_line(int fd, char **line);

t_fdnode *find_or_create_fdnode(int fd, t_fdnode **list);
void remove_fdnode(int fd, t_fdnode **list);

char *ft_strchr (const char *str, int c);
size_t ft_strlen (const char *str);
size_t ft_strlcpy (char *dst, const char *src, size_t size);
char *ft_strjoin (const char *s1, char const *s2);
void *ft_memcpy (void *dst, const void *src, size_t n);
char *ft_strdup (char *s1);

#endif
