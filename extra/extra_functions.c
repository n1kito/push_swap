//
// Functions that I ended up not using
//

/* Sorts the first 3 items of a stack larger than 3 */
// -TODO Make this smaller

void	ft_sort_top_three(t_list **stack, t_log **actions)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->data;
	second = (*stack)->next->data;
	third = (*stack)->next->next->data;
	if (first < second && first < third && second > third)
	{
		op_rotate(stack, actions);
		op_swap(stack, actions);
		op_rev_rotate(stack, actions);
	}
	else if (first < second && first > third && second > third)
	{
		op_rotate(stack, actions);
		op_rev_rotate(stack, actions);
		op_swap(stack, actions);
	}
	else if (first > second && first > third && second > third)
	{
		op_swap(stack, actions);
		op_rotate(stack, actions);
		op_swap(stack, actions);
		op_rev_rotate(stack, actions);
		op_swap(stack, actions);
	}
	else if (first > second && first > third && second < third)
	{
		op_swap(stack, actions);
		op_rotate(stack, actions);
		op_swap(stack, actions);
		op_rev_rotate(stack, actions);
	}
	else if (first > second && first < third && second < third)
		op_swap(stack, actions);
	ft_set_stack_as_sorted(stack, 3);
}

/* Returns the len of an int, handles negative ints */

int	get_int_len(int nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
		i++;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

/* Prints a linked list horizontally */

void	lst_horizontal_print(t_list *printme)
{
	t_list	*current;

	current = printme;
	printf("{");
	while (current)
	{
		printf("%d", current->data);
		if (current->is_sorted == 1)
			printf("*");
		if (current->next)
			printf(", ");
		current = current->next;
	}
	printf("}\n");
}

/* Sets entire stack as sorted */
// -TODO je sais pas si je l'utilise celle-ci
void	ft_set_stack_as_sorted(t_list **stack)
{
	t_list	*current;

	current = *stack;
	while (current)
	{
		current->is_sorted = 1;
		if (current->next == NULL)
			return ;
		current = current->next;
	}
}

int	ft_lst_len(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

