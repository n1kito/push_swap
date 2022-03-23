/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjallada <mjallada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:26:09 by mjallada          #+#    #+#             */
/*   Updated: 2022/02/01 17:26:12 by mjallada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	op_push(t_list **dest, t_list **src, t_log **actions)
{
	t_list	*src_head;

	src_head = *src;
	if (*dest == NULL)
		op_push_to_empty_list(dest, src);
	else if (*src && (*src)->next == NULL)
		op_push_from_list_of_one(dest, src);
	else
	{
		if ((*src)->next)
			src_head->next->len = src_head->len - 1;
		(*src)->len = (*dest)->len + 1;
		*src = (*src)->next;
		(*src)->previous = NULL;
		src_head->next = *dest;
		(*dest)->previous = src_head;
		(*dest) = src_head;
	}
	push_logger(dest, actions);
	lst_indexer(src);
	lst_indexer(dest);
}

void	op_push_to_empty_list(t_list **dest, t_list **src)
{
	t_list	*src_head;

	src_head = *src;
	if (*src != NULL && (*src)->next != NULL)
		src_head->next->len = src_head->len - 1;
	*dest = src_head;
	*src = src_head->next;
	(*dest)->len = 1;
	(*dest)->next = NULL;
}

void	op_push_from_list_of_one(t_list **dest, t_list **src)
{
	t_list	*src_head;

	src_head = *src;
	src_head->len = (*dest)->len + 1;
	(*dest)->len = 0;
	(*dest)->previous = src_head;
	src_head->next = *dest;
	*dest = src_head;
	*src = NULL;
}

void	push_logger(t_list **dest, t_log **actions)
{
	if (*dest && (*dest)->current_stack == 'A')
	{
		(*dest)->current_stack = 'B';
		ft_add_to_log(actions, "pb");
	}
	else if (*dest && (*dest)->current_stack == 'B')
	{
		(*dest)->current_stack = 'A';
		ft_add_to_log(actions, "pa");
	}
}
