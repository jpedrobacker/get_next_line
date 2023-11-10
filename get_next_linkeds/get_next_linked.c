#include "get_next_linked.h"

char    *get_line(t_list *list)
{

}

char    *get_next_line(int fd)
{
    static t_list   *list;
    char    *next_line;

    list = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
	return (NULL);
    list = ft_lstnew(list);
}