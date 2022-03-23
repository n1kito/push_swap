#include "libft.h"

void	lst_double_stack_print(char a, t_list *lst_a, char b, t_list *lst_b)
{
	int len_a;
	int len_b;
	int len_max;

	len_a = ft_lstsize(lst_a);
	len_b = ft_lstsize(lst_b);
	(len_a > len_b) ? (len_max = len_a) : (len_max = len_b);
	while (len_max--)
	{
		len_a ? printf("%d", lst_a->data) : printf(" ");
		printf("  ");
		(len_b > 0) ? printf("%d", lst_b->data) : printf(" ");
		printf("\n");
		if (len_a > 0)
			lst_a = lst_a->next;
		if (len_b > 0)
			lst_b = lst_b->next;
		len_a--;
		len_b--;
	}
	printf("–  –\n");
	printf("%c  %c\n", a, b);
}

