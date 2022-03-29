/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjallada <mjallada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:45:12 by mjallada          #+#    #+#             */
/*   Updated: 2022/03/21 17:08:54 by mjallada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			**ft_split(char const *s, char c);
void			ft_putstr(char *str);

typedef struct s_cost
{
	int			total_cost;
	int			ra;
	int			rb;
	int			rra;
	int			rrb;
	int			rr;
	int			rrr;
}				t_cost;

typedef struct s_list
{
	int				data;
	int				len;
	char			current_stack;
	int				index;
	int				sort_index;
	int				is_sorted;
	struct s_cost	*cost;
	struct s_list	*previous;
	struct s_list	*next;
}					t_list;

t_list			*ft_lstlast(t_list *lst);

#endif
