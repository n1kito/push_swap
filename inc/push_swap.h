/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjallada <mjallada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:54:06 by mjallada          #+#    #+#             */
/*   Updated: 2022/03/22 07:55:17 by mjallada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ########################################################################## */
/* INCLUDES */

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

/* ########################################################################## */
/* STRUCTURES */

typedef struct s_log
{
	char			*action;
	struct s_log	*next;
}				t_log;

/* ########################################################################## */
/* FUNCTIONS */

/* Argument checker */
int			lst_duplicate_check(t_list *stack, int check_me);
int			args_digit_check(char *arg);

/* Argument parsing */
int			args_to_list(int arg_count, char **argv, t_list **stack_a);
int			lst_add_last(t_list **stack, char *arg);
void		new_node_setup(t_list **new_node);
void		reset_node_costs(t_list **node);

/* Operation push */
void		op_push(t_list **dest, t_list **src, t_log **actions);
void		op_push_to_empty_list(t_list **dest, t_list **src);
void		op_push_from_list_of_one(t_list **dest, t_list **src);
void		push_logger(t_list **dest, t_log **actions);

/* Operation rotate */
void		op_rotate(t_list **stack, t_log **actions);
void		op_rotate_both(t_list **stack, t_list **stack2, t_log **actions);
void		op_rev_rotate(t_list **stack, t_log **actions);
void		op_rev_rotate_both(t_list **s, t_list **s2, t_log **actions);
void		ft_remove_latest_log(t_log **actions);

/* Operation swap */
void		op_swap(t_list **list, t_log **actions);

/* Sorting utils */
void		smart_rotate(t_list **stack, int index, t_log **actions);
void		smart_push(t_list **s1, t_list **s2, t_log **actions, int index);
void		sm_psh_l_o_s(t_list **stack, t_list **stack2, t_log **actions);
int			find_biggest_num_i(t_list *stack);
int			find_smallest_num_i(t_list *stack);

/* Push swap utils */
void		print_log(t_log *actions);
void		ft_add_to_log(t_log **actions, char *action);
long int	ft_atol(const char *nptr);
int			get_int_len(int nbr);
void		lst_sort_indexer(t_list **stack);
void		lst_indexer(t_list **stack);
void		ft_set_stack_as_sorted(t_list **stack, int n);

/* Sort small list */
void		ft_sort_two(t_list **stack, t_log **actions);
void		ft_sort_three(t_list **stack, t_log **actions);

/* Sort average list */
void		selection_sort(t_list **stack, t_list **stack2, t_log **actions);
int			lst_is_sorted(t_list *list);

/* Sort long list */
void		cost_sort(t_list **stack, t_list **stack2, t_log **actions);
void		push_cheapest(t_list **s, t_list **s2, t_log **actions, int cutoff);
void		opti_push(t_list **s, t_list **s2, int index, t_log **actions);
int			find_cheapest_index(t_list *stack);
void		find_next_higher_num_i(int item_sort_index, t_list *s, int *index);

/* Cost management */
void		cost_calculator(t_list **item, t_list **s, t_list **s2);
void		optimize_moves(t_list	**item);
void		calc_total_move_cost(t_list **item);

/* Sort GPS */
void		sort_gps(t_list **stack_a, t_list **stack_b, t_log **actions);

/* Free functions */
void		free_stack(t_list *stack);
void		free_log(t_log *actions_log);

#endif
