/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjallada <mjallada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:08:18 by mjallada          #+#    #+#             */
/*   Updated: 2022/02/01 17:08:37 by mjallada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rotate(t_list **stack, t_log **actions)
{
	t_list	*head;
	t_list	*tail;
	t_list	*tmp;

	if ((*stack)->next != NULL)
	{
		tmp = *stack;
		head = (*stack)->next;
		head->len = tmp->len;
		tmp->len = 0;
		tail = ft_lstlast(*stack);
		head->previous = NULL;
		tmp->previous = tail;
		tmp->next = NULL;
		tail->next = tmp;
		*stack = head;
		if ((*stack)->current_stack == 'A')
			ft_add_to_log(actions, "ra");
		else if ((*stack)->current_stack == 'B')
			ft_add_to_log(actions, "rb");
		lst_indexer(stack);
	}
}

void	ft_remove_latest_log(t_log **actions)
{
	t_log	*sec_to_last;
	t_log	*last;

	sec_to_last = *actions;
	while (sec_to_last->next && sec_to_last->next->next)
		sec_to_last = sec_to_last->next;
	last = sec_to_last->next;
	sec_to_last->next = NULL;
	free(last->action);
	free(last);
}

void	op_rotate_both(t_list **stack, t_list **stack2, t_log **actions)
{
	op_rotate(stack, actions);
	ft_remove_latest_log(actions);
	op_rotate(stack2, actions);
	ft_remove_latest_log(actions);
	ft_add_to_log(actions, "rr");
}

void	op_rev_rotate(t_list **stack, t_log **actions)
{
	t_list	*head;
	t_list	*tail;

	if ((*stack) && (*stack)->next)
	{
		head = *stack;
		tail = ft_lstlast(*stack);
		tail->len = head->len;
		head->len = 0;
		tail->previous->next = NULL;
		tail->previous = NULL;
		tail->next = head;
		head->previous = tail;
		*stack = tail;
		if ((*stack)->current_stack == 'A')
			ft_add_to_log(actions, "rra");
		else if ((*stack)->current_stack == 'B')
			ft_add_to_log(actions, "rrb");
		lst_indexer(stack);
	}
}

void	op_rev_rotate_both(t_list **stack, t_list **stack2, t_log **actions)
{
	op_rev_rotate(stack, actions);
	ft_remove_latest_log(actions);
	op_rev_rotate(stack2, actions);
	ft_remove_latest_log(actions);
	ft_add_to_log(actions, "rrr");
}
