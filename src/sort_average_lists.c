/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_average_lists.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjallada <mjallada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 09:00:40 by mjallada          #+#    #+#             */
/*   Updated: 2022/02/22 09:00:51 by mjallada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_list **stack, t_list **stack2, t_log **actions)
{
	int	smallest_number_index;

	while (*stack && !lst_is_sorted(*stack))
	{
		smallest_number_index = find_smallest_num_i(*stack);
		smart_rotate(stack, smallest_number_index, actions);
		if (!lst_is_sorted(*stack))
		{
			(*stack)->is_sorted = 1;
			op_push(stack2, stack, actions);
		}
		sort_gps(stack, stack2, actions);
	}
	while ((*stack2) && (*stack2)->is_sorted)
		op_push(stack, stack2, actions);
}

/* Checks if list is sorted. */

int	lst_is_sorted(t_list *list)
{
	t_list	*current;

	current = list;
	while (current && current->next)
	{
		if (current->next->data > current->data)
		{
			current = current->next;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

/* Sets n numbers in stack as sorted.
 * If n <= 0, the entire list is set as sorted. */

void	ft_set_stack_as_sorted(t_list **stack, int n)
{
	t_list	*current;
	int		i;

	i = 0;
	current = *stack;
	if (n <= 0)
		n = (*stack)->len;
	while (current && (i++ < n))
	{
		current->is_sorted = 1;
		if (current->next == NULL)
			return ;
		current = current->next;
	}
}
