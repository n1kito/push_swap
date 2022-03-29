/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjallada <mjallada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:30:32 by mjallada          #+#    #+#             */
/*   Updated: 2022/03/21 17:20:52 by mjallada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Outputs log of operations */

void	print_log(t_log *actions)
{
	t_log	*current;

	current = actions;
	while (current)
	{
		ft_putstr(current->action);
		ft_putstr("\n");
		if (!current->next)
			break ;
		current = current->next;
	}
}

/* Adds operations to log */

void	ft_add_to_log(t_log **actions, char *action)
{
	t_log	*current;
	t_log	*new_node;
	int		action_len;

	current = *actions;
	action_len = (int)ft_strlen(action);
	new_node = malloc(sizeof(t_log));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->action = malloc(sizeof(char) * (action_len + 1));
	if (new_node->action == NULL)
		return ;
	ft_strlcpy(new_node->action, action, action_len + 1);
	if (current == NULL)
		*actions = new_node;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}

long int	ft_atol(const char *nptr)
{
	long int	num;
	int			sign;
	int			i;

	num = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		num = (num * 10) + (nptr[i] - 48);
		i++;
	}
	return (num * sign);
}

/* Used when push_swap is launched. Indexes each element in the same manner
 * as they would be in an array, so I know where they're supposed to end
 * up and can calculate the cost to move them accordingly */

void	lst_sort_indexer(t_list **stack)
{
	t_list	*comparator;
	t_list	*current;

	current = *stack;
	while (current)
	{
		current->sort_index = 0;
		comparator = *stack;
		while (comparator)
		{
			if (current->data > comparator->data)
				current->sort_index += 1;
			comparator = comparator->next;
		}
		current = current->next;
	}
}

/* Indexes my stacks. Has to be redone with every operation so not very
 * efficient. */

void	lst_indexer(t_list **stack)
{
	t_list	*current;
	int		i;

	current = *stack;
	i = 0;
	while (current)
	{
		current->index = i++;
		if (current->next)
			current = current->next;
		else
			return ;
	}
}
