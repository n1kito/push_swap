/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjallada <mjallada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:24:24 by mjallada          #+#    #+#             */
/*   Updated: 2022/02/18 08:24:43 by mjallada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_gps(t_list **stack_a, t_list **stack_b, t_log **actions)
{
	if (!(*stack_a))
		return ;
	if ((*stack_a)->len == 2)
		ft_sort_two(stack_a, actions);
	else if ((*stack_a)->len == 3)
		ft_sort_three(stack_a, actions);
	else
		cost_sort(stack_a, stack_b, actions);
}
