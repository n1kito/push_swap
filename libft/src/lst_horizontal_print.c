#include "libft.h"

void	lst_horizontal_print(t_list *printme)
{
	t_list	*current;

	current = printme;
	printf("{");
	while (current)
	{
		printf("%d", current->data);
		if (current->next)
			printf(", ");
		current = current->next;
	}
	printf("}\n");
}