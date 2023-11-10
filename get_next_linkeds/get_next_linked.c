#include "get_next_linked.h"

char    *make_list(t_list **list, int fd)
{

}

char    *get_next_line(int fd)
{
    static t_list   *list;
    char    *next_line;

    list = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
	return (NULL);
    make_list(&list, fd);
}