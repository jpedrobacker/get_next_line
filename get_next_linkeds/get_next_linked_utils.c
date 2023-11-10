#include "get_next_linked.h"

void	*ft_lstnew(void **list, int fd)
{
	t_list	*new;
    
    while (!to_find)
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			temp = ft_lstlast(*(lst));
			temp->next = new;
		}
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*begin;
	t_list	*temp;

	begin = (*(lst));
	while (begin != NULL)
	{
		temp = begin->next;
		ft_lstdelone(begin, del);
		begin = temp;
	}
	*lst = NULL;
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
	lst = NULL;
}