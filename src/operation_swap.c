/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjallada <mjallada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:08:18 by mjallada          #+#    #+#             */
/*   Updated: 2022/03/21 17:03:34 by mjallada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* this file has the swapping functions: sa, sb ss */

void	op_swap(t_list **list, t_log **actions)
{
	t_list	*head;
	t_list	*new_head;

	head = *list;
	if (head && head->next != NULL)
	{
		new_head = head->next;
		new_head->len = head->len;
		head->len = 0;
		new_head->previous = head->previous;
		if (new_head->next)
			new_head->next->previous = head;
		head->next = new_head->next;
		new_head->next = head;
		head->previous = new_head;
		*list = new_head;
	}
	lst_indexer(list);
	if (*list && (*list)->current_stack == 'A')
		ft_add_to_log(actions, "sa");
	else if (*list && (*list)->current_stack == 'B')
		ft_add_to_log(actions, "sb");
}
