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

#include "../include/push_swap.h"

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

/* Finds largest and smallest number indexes and decides which one to smart_push
 * depending on their position in the stack and in relation to each other */

//void	sm_psh_l_o_s(t_list **stack, t_list **stack2, t_log **actions)
//{
//	int	largest_index;
//	int	smallest_index;
//	int	middle_of_list;
//
//	largest_index = find_biggest_num_i(*stack);
//	smallest_index = find_smallest_num_i(*stack);
//	middle_of_list = ((*stack)->len - 1) / 2;
//	if (largest_index < middle_of_list && smallest_index < middle_of_list)
//	{
//		if (largest_index < smallest_index)
//			smart_push(stack, stack2, actions, largest_index);
//		else
//		{
//			smart_push(stack, stack2, actions, smallest_index);
//			op_rotate(stack2, actions);
//		}
//	}
//	else
//	{
//		if (largest_index > smallest_index)
//			smart_push(stack, stack2, actions, largest_index);
//		else
//		{
//			smart_push(stack, stack2, actions, smallest_index);
//			op_rotate(stack2, actions);
//		}
//	}
//}

/* Finds the position of the biggest number in the stack.
 * Used for smart rotate and smart push */

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

/* Finds the position of the smallest number in the stack.
 * Used for smart rotate and smart push */

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
