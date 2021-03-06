/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjallada <mjallada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:53:58 by mjallada          #+#    #+#             */
/*   Updated: 2022/03/30 07:48:42 by mjallada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_log		*actions_log;

	nullify(&stack_a, &stack_b, &actions_log);
	if (argc > 1)
	{
		if (!args_to_list(argc, argv, &stack_a))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		if (lst_is_sorted(stack_a))
		{
			free_stack(stack_a);
			return (0);
		}
		lst_sort_indexer(&stack_a);
		sort_gps(&stack_a, &stack_b, &actions_log);
		print_log(actions_log);
		free_stack(stack_a);
		free_log(actions_log);
	}
	return (0);
}

void	nullify(t_list **stack_a, t_list **stack_b, t_log **actions_log)
{
	*stack_a = NULL;
	*stack_b = NULL;
	*actions_log = NULL;
	return ;
}
