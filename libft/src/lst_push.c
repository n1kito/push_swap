#include "libft.h"

void	lst_push(t_list **head_ref, int data)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	new_node->data = data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}