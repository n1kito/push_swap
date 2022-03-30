/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjallada <mjallada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:35:46 by mjallada          #+#    #+#             */
/*   Updated: 2022/03/30 08:15:30 by mjallada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list *stack)
{
	t_list	*current;
	t_list	*tmp;

	current = stack;
	while (current)
	{
		free(current->cost);
		tmp = current;
		current = current->next;
		free(tmp);
	}
}

void	free_log(t_log *actions_log)
{
	t_log	*current;
	t_log	*tmp;

	current = actions_log;
	while (current)
	{
		free(current->action);
		tmp = current;
		current = current->next;
		free(tmp);
	}
}

void	free_parsing(char **divided_args, t_list **stack)
{
	free(divided_args[0]);
	free(divided_args);
	free_stack(*stack);
	return ;
}
