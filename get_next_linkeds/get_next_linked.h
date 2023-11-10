#ifndef GET_NEXT_LINKED_H
# define GET_NEXT_LINKED_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
    char            *content;
    struct s_list   *next;
}   t_list;

void	find_line(t_list *list);
t_list	*ft_lstlast(t_list *lst);

#endif
