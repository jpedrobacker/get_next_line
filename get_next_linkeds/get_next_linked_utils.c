#include "get_next_linked.h"

void	find_line(t_list *list)
{
    int i;
    
    if (NULL == list)
        return (NULL);
    while (list)
    {
        i = 0;
        while(list->content[i] && i < BUFFER_SIZE)
        {
            if (list->content[i] == '\n')
                return (1);
            i++;
        }
        list = list->next;
    }
    return (NULL);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	if (temp == NULL)
		return (NULL);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}