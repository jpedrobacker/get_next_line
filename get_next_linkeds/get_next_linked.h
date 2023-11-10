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
    void            *content;
    struct s_list   *next;
}   t_list;

void	*ft_lstnew(void **list, int fd);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));

#endif
