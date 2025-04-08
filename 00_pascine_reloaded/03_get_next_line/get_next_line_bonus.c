#include <stdio.h>
#include <unistd.h>
#include "get_next_line_bonus.h"
#include "get_next_line.h"

int get_next_line (int fd, char **line)
{
    if (fd < 0 || !line) {
        return -1;
    }

    static t_fdnode *fdlist = NULL;
    t_fdnode *node = find_or_create_fdnode(fd, &fdlist);

    if (node->buf == NULL && node->is_binary == 0) {
        node->is_binary = check_binary(fd);
        if (node->is_binary) {
            remove_fdnode(fd, &fdlist);
            return -1;
        }
    }


    if (!node->buf) {
        node->buf = ft_strdup("");
        if (!node->buf) {
            remove_fdnode(fd, &node);
            return -1;
        }
    }

    while (!ft_strchr(node->buf, '\n')) {
        int status = read_to_buffer(fd, &node->buf);
        if (status == -1) {
            remove_fdnode(fd, &node);
            return -1;
        }
        if (status == 0) {
            break;
        }
    }
    int result = extract_line(&node->buf, line);
    if (result == 0 || result == -1) {
        remove_fdnode(fd, &fdlist);
    }

    return result;

}
