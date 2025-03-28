#include "libft.h"
static size_t count_words (char const *s, char c) {
    size_t count;
    int w;
    count = 0;
    w = 0;
    while (*s) {
        if (*s != c && !w) {
            w = 1;
            count++;
        }
        else if (*s == c) {
            w = 0;
        }
        s++;
    }
    return count;
}

static char *get_word (const char *s, char c, size_t *pos) {
    size_t start;
    size_t end;
    char *word;

    while (s[*pos] == c) {
        (*pos)++;
    }
    start = *pos;
    while (s[*pos] && s[*pos] != c) {
        (*pos)++;
    }
    end = *pos;
    word = (char *)malloc(sizeof(char) * (end - start + 1));
    if (!word) {
        return NULL;
    }
    ft_memcpy(word, &s[start], end - start);
    word[end - start] = '\0';

    return word;
}

char **ft_split (const char *s, char c) {
    char **result;
    size_t word_count;
    size_t i;
    size_t pos;
    if (!s) {
        return NULL;
    }
    word_count = count_words(s, c);
    result = (char **)malloc(sizeof(char *) * (word_count + 1));
    if (!result) {
        return NULL;
    }

    i = 0;
    pos = 0;
    while (i < word_count) {
        result[i] = get_word(s, c, &pos);
        if (!result[i]) {
            while (i > 0) {
                free(result[--i]);
            }
            free(result);
            return NULL;
        }
        i++;
    }
    return result;
}
