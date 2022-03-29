/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjallada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:41:02 by mjallada          #+#    #+#             */
/*   Updated: 2022/02/08 15:41:05 by mjallada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks for duplicate numbers in arguments */

int	lst_duplicate_check(t_list *stack, int check_me)
{
	while (stack)
	{
		if (stack->data == check_me)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* Checks that arguments are actually digits and, if they have a sign,
 * that they only have one. */

int	args_digit_check(char *arg)
{
	int	i;

	i = 0;
	if ((arg[i] == '-' || arg[i] == '+' || ft_isdigit(arg[i]))
		&& ft_strlen(arg) <= 11)
	{
		if ((arg[i] == '-' || arg[i] == '+') && !ft_isdigit(arg[i + 1]))
			return (0);
		i++;
		while (arg[i])
		{
			if (!ft_isdigit(arg[i]))
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
