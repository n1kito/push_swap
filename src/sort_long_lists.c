/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_lists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjallada <mjallada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 08:58:33 by mjallada          #+#    #+#             */
/*   Updated: 2022/03/22 08:08:31 by mjallada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sorts using cost of sorting each item in the list*/

void	cost_sort(t_list **stack, t_list **stack2, t_log **actions)
{
	t_list	*current;
	int		nums_to_keep;

	current = *stack;
	nums_to_keep = (*stack)->len - 10;
	if (current->len <= 10)
	{
		selection_sort(stack, stack2, actions);
		return ;
	}
	while (current)
	{
		if (current->sort_index < nums_to_keep)
		{
			smart_push(stack, stack2, actions, current->index);
			break ;
		}
		current = current->next;
	}
	while ((*stack)->len > 10)
		push_cheapest(stack, stack2, actions, nums_to_keep);
	smart_rotate(stack2, find_biggest_num_i(*stack2), actions);
	selection_sort(stack, stack2, actions);
	while (*stack2)
		op_push(stack, stack2, actions);
}

/* Looks at action count of all items in a list and pushes the cheapest one */

void	push_cheapest(t_list **s, t_list **s2, t_log **actions, int cutoff)
{
	t_list	*current;
	int		index_of_cheapest_item_to_move;

	current = *s;
	while (current)
	{
		if (current->sort_index >= cutoff)
			current->cost->total_cost = 2147483647;
		else
			cost_calculator(&current, s, s2);
		current = current->next;
	}
	index_of_cheapest_item_to_move = find_cheapest_index(*s);
	opti_push(s, s2, index_of_cheapest_item_to_move, actions);
}

/* Pushes number to other list using optimized operations */

void	opti_push(t_list **stack, t_list **stack2, int index, t_log **actions)
{
	t_list	*current;
	int		i;

	current = *stack;
	i = 0;
	while (current && i++ < index)
		current = current->next;
	if (current == NULL)
		return ;
	while (current->cost->rr--)
		op_rotate_both(stack, stack2, actions);
	while (current->cost->rrr--)
		op_rev_rotate_both(stack, stack2, actions);
	while (current->cost->ra--)
		op_rotate(stack, actions);
	while (current->cost->rb--)
		op_rotate(stack2, actions);
	while (current->cost->rra--)
		op_rev_rotate(stack, actions);
	while (current->cost->rrb--)
		op_rev_rotate(stack2, actions);
	op_push(stack2, stack, actions);
}

/* Finds the item with the least amount of moves and returns its index
 * Function based on the find_smallest_num_i function */

int	find_cheapest_index(t_list *stack)
{
	int		i;
	t_list	*head;
	t_list	*current;
	t_list	*cmp;

	head = stack;
	current = stack;
	i = 0;
	while (current && current->next)
	{
		cmp = head;
		while (current->cost->total_cost <= cmp->cost->total_cost && cmp->next)
			cmp = cmp->next;
		if (current->cost->total_cost <= cmp->cost->total_cost && !cmp->next)
			return (i);
		i++;
		current = current->next;
	}
	return (i);
}

/* Find the index of the items that has the next highest sort index.
 * Used to calculate cost of rotating the stack to receive that number
 * since to receive any number in a stack, the sec_to_last item of the stack
 * must be the next biggest index. And that works even to push an item
 * that will be the smallest in the stack. */

void	find_next_higher_num_i(int item_sort_index, t_list *stack, int *index)
{
	int	latest_index_found;

	latest_index_found = 0;
	while (stack)
	{
		if (stack->sort_index > item_sort_index)
		{
			if (latest_index_found == 0)
			{
				latest_index_found = stack->sort_index;
				*index = stack->index;
			}
			else
			{
				if (stack->sort_index < latest_index_found)
				{
					latest_index_found = stack->sort_index;
					*index = stack->index;
				}
			}
		}
		stack = stack->next;
	}
}
