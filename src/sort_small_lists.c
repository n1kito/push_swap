/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjallada <mjallada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 08:20:15 by mjallada          #+#    #+#             */
/*   Updated: 2022/03/21 17:17:55 by mjallada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sorts the first 2 items of any list */

void	ft_sort_two(t_list **stack, t_log **actions)
{
	op_swap(stack, actions);
	ft_set_stack_as_sorted(stack, 0);
}

/* Sorts the first 3 items of a stack of 3 */

void	ft_sort_three(t_list **stack, t_log **actions)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->data;
	second = (*stack)->next->data;
	third = (*stack)->next->next->data;
	if (first < second && first < third && second > third)
	{
		op_rev_rotate(stack, actions);
		op_swap(stack, actions);
	}
	else if (first < second && first > third && second > third)
		op_rev_rotate(stack, actions);
	else if (first > second && first > third && second > third)
	{
		op_swap(stack, actions);
		op_rev_rotate(stack, actions);
	}
	else if (first > second && first > third && second < third)
		op_rotate(stack, actions);
	else if (first > second && first < third && second < third)
		op_swap(stack, actions);
	ft_set_stack_as_sorted(stack, 0);
}
