/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjallada <mjallada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 08:26:55 by mjallada          #+#    #+#             */
/*   Updated: 2022/02/22 08:27:20 by mjallada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Rotates item to top of stack in the least amount of operations */

void	smart_rotate(t_list **stack, int index, t_log **actions)
{
	if (index <= ((*stack)->len - 1) / 2)
	{
		while (index--)
			op_rotate(stack, actions);
	}
	else
		while (index++ != (*stack)->len)
			op_rev_rotate(stack, actions);
}

/* Pushes items to other stack in the least amount of operations */

void	smart_push(t_list **stack, t_list **stack2, t_log **actions, int index)
{
	smart_rotate(stack, index, actions);
	op_push(stack2, stack, actions);
}

/* Finds the index of the biggest number in the stack.
 * Used for smart rotate and smart push. */

int	find_biggest_num_i(t_list *stack)
{
	int		i;
	t_list	*head;
	t_list	*current;
	t_list	*compared;

	head = stack;
	current = stack;
	i = 0;
	while (current && current->next)
	{
		compared = head;
		while (current->data >= compared->data && compared->next)
			compared = compared->next;
		if (current->data >= compared->data && compared->next == NULL)
			return (i);
		i++;
		current = current->next;
	}
	return (i);
}

/* Finds the index of the smallest number in the stack.
 * Used for smart rotate and smart push. */

int	find_smallest_num_i(t_list *stack)
{
	int		i;
	t_list	*head;
	t_list	*current;
	t_list	*compared;

	head = stack;
	current = stack;
	i = 0;
	while (current && current->next)
	{
		compared = head;
		while (current->data <= compared->data && compared->next)
			compared = compared->next;
		if (current->data < compared->data && compared->next == NULL)
			return (i);
		i++;
		current = current->next;
	}
	return (i);
}
