#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>

int ft_atoi (const char *str);
void ft_bzero (char *str, size_t n);
void *ft_calloc (size_t num, size_t size);
char *ft_strdup (char *s1);
void *ft_memccpy (void *dst, const void *src, int c, size_t n);
void ft_memchr (const void *s1, int c, size_t n);
int ft_memcmp (const void *s1, const void *s2, size_t n);
void *ft_memcpy (void *dst, const void *src, size_t n);
void *ft_memmove (void *dst, const void *src, size_t len);
void *ft_memset (char *str, int c, size_t len);
char ft_strchr (const char *str, int c);
size_t ft_strlcat (char *dst, const char *src, size_t size);
int ft_strlcpy (char *dst, const char *src, size_t size);
int ft_strlen (char *str);
int ft_strncmp (char *s1, char *s2, size_t n);
char *ft_strnstr (const char *source, const char *needle, size_t len);
char *ft_strrchr (const char *str, int num);

int ft_isalnum (int c);
int ft_isalpha (int c);
int	ft_isascii(int c);
int ft_isdigit (int num);
int ft_is_print (int c);
int ft_tolower (int c);
int ft_toupper (int c);

#endi
