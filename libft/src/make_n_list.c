#include "libft.h"

t_list	*make_n_list(int n)
{
	t_list	*head;
	t_list	*tail;
	int 	i;

	if (n == 0)
		return (NULL);
	head = NULL;
	lst_push(&head, 1);
	tail = head;
	i = 1;
	while (++i < (n + 1))
	{
		lst_push(&(tail->next), i);
		tail = tail->next;
	}
	return (head);
}