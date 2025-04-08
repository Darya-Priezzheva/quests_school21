#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>


int get_next_line (int fd, char **line);
char *ft_strchr (const char *str, int c);
size_t ft_strlen (const char *str);
size_t ft_strlcpy (char *dst, const char *src, size_t size);
char *ft_strjoin (const char *s1, char const *s2);
void *ft_memcpy (void *dst, const void *src, size_t n);
char *ft_strdup (char *s1);


int read_to_buffer (int fd, char **buffer);
int extract_line (char **buffer, char **line);
void all_free (char **buffer);
int check_binary (int fd);

#endif
