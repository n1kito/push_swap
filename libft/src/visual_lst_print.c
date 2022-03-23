#include "libft.h"

void	visual_lst_print(t_list *lst)
{
	int	item_len;
	int	lst_len;
	int	i;
	t_list	*current;

	current = lst;
	lst_len = ft_lstsize(lst);

	// TOP ROW
	i = lst_len;
	int j = 0;
	while(i--)
	{
		item_len = ft_strlen(current->content);
		printf("+");
		j = 0;
		while (j++ < (item_len + 4))
			printf("-");
		printf("+-----+");
		printf("    ");
		current = current->next;
	}
	printf("\n");

	// MIDDLE ROW
	i = lst_len;
	current = lst;
	while (i--)
	{
		printf("|  %s  |", (char *)current->content);
		if (i > 0)
			printf("   ------>");
		else
			printf("  /  |");
		current = current->next;
	}
	printf("\n");

	// BOTTOM ROW
	i = lst_len;
	current = lst;
	while(i--)
	{
		item_len = ft_strlen(current->content);
		printf("+");
		j = 0;
		while (j++ < (item_len + 4))
			printf("-");
		printf("+-----+");
		printf("    ");
		current = current->next;
	}
	printf("\n");
}
