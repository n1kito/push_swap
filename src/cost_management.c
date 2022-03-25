/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjallada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:51:14 by mjallada          #+#    #+#             */
/*   Updated: 2022/03/21 14:51:16 by mjallada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* Calculates cost to push to other list, taking into account:
 * rotations needed to push from stack_a, rotations needed to receive in stack_b
 * the actual push (+1), and including optimisations with ss, rr & rrr. */

void	cost_calculator(t_list **item, t_list **s, t_list **s2)
{
	int	nxt_bigr_i_in_b;

	reset_node_costs(item);
	if ((*item)->index <= (((*s)->len - 1) / 2))
		(*item)->cost->ra = (*item)->index;
	else
		(*item)->cost->rra = (*s)->len - (*item)->index;
	nxt_bigr_i_in_b = -1;
	find_next_higher_num_i((*item)->sort_index, *s2, &nxt_bigr_i_in_b);
	if ((nxt_bigr_i_in_b == -1 || nxt_bigr_i_in_b == 0) && (*s2)->len == 1)
		(*item)->cost->rb = 0;
	else if (nxt_bigr_i_in_b == -1)
	{
		if (find_biggest_num_i(*s2) <= (((*s2)->len - 1) / 2))
			(*item)->cost->rb = find_biggest_num_i(*s2);
		else
			(*item)->cost->rrb = (*s2)->len - find_biggest_num_i(*s2);
	}
	else if (nxt_bigr_i_in_b <= (((*s2)->len - 1) / 2))
		(*item)->cost->rb = nxt_bigr_i_in_b + 1;
	else
		(*item)->cost->rrb = ((*s2)->len - nxt_bigr_i_in_b) - 1;
	optimize_moves(item);
	calc_total_move_cost(item);
}

/* Optimizes ra + rb into rr and rra + rrb into rrr */

void	optimize_moves(t_list	**item)
{
	while ((*item)->cost->ra && (*item)->cost->rb)
	{
		(*item)->cost->ra -= 1;
		(*item)->cost->rb -= 1;
		(*item)->cost->rr += 1;
	}
	while ((*item)->cost->rra && (*item)->cost->rrb)
	{
		(*item)->cost->rra -= 1;
		(*item)->cost->rrb -= 1;
		(*item)->cost->rrr += 1;
	}
}

/* Adds up every move necessary to push the number to its correct spot in the
 * second stack. Ending +1 for the obligatory push. */

void	calc_total_move_cost(t_list **item)
{
	int	total_moves;

	total_moves = (*item)->cost->ra;
	total_moves += (*item)->cost->rb;
	total_moves += (*item)->cost->rra;
	total_moves += (*item)->cost->rrb;
	total_moves += (*item)->cost->rr;
	total_moves += (*item)->cost->rrr;
	total_moves += 1;
	(*item)->cost->total_cost = total_moves;
}
