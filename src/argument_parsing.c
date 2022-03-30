/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjallada <mjallada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:57:41 by mjallada          #+#    #+#             */
/*   Updated: 2022/03/30 08:11:11 by mjallada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function checks the input, if the input arguments respect the subject
 * requirement they get added to stack_a and the function returns (1),
 * if any of the argument checkers failed, the function returns (0); */

int	args_to_list(int arg_count, char **argv, t_list **stack_a)
{
	int		i;
	int		j;
	char	**divided_args;

	i = 1;
	while (--arg_count)
	{
		divided_args = ft_split(argv[i++], ' ');
		j = 0;
		while (divided_args[j])
		{
			if (!args_digit_check(divided_args[j])
				|| !lst_duplicate_check(*stack_a, (int)ft_atol(divided_args[j]))
				|| !lst_add_last(stack_a, divided_args[j]))
			{
				free_parsing(divided_args, stack_a);
				return (0);
			}
			j++;
		}
		free(divided_args[0]);
		free(divided_args);
	}
	lst_indexer(stack_a);
	return (1);
}

/* Adds argument to end of stack */

int	lst_add_last(t_list **stack, char *arg)
{
	t_list	*current;
	t_list	*new_node;

	if (ft_atol(arg) > 2147483647 || ft_atol(arg) < -2147483648)
		return (0);
	current = *stack;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->data = (int)ft_atol(arg);
	new_node_setup(&new_node);
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		while (current && current->next)
			current = current->next;
		current->next = new_node;
		new_node->previous = current;
	}
	(*stack)->len += 1;
	return (1);
}

void	new_node_setup(t_list **new_node)
{
	(*new_node)->next = NULL;
	(*new_node)->previous = NULL;
	(*new_node)->len = 0;
	(*new_node)->is_sorted = 0;
	(*new_node)->current_stack = 'A';
	(*new_node)->sort_index = -1;
	(*new_node)->cost = malloc(sizeof (t_cost));
	if ((*new_node)->cost == NULL)
		return ;
	reset_node_costs(new_node);
}

/* Sets/Resets all costs associated to a node */

void	reset_node_costs(t_list **node)
{
	(*node)->cost->total_cost = 0;
	(*node)->cost->ra = 0;
	(*node)->cost->rb = 0;
	(*node)->cost->rra = 0;
	(*node)->cost->rrb = 0;
	(*node)->cost->rr = 0;
	(*node)->cost->rrr = 0;
}
