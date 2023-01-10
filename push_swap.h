/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:17:47 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/10 12:56:57 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_list
{
	int				value;
	int				position;
	struct s_list	*next;
}					t_nlist;

void		free_list(t_nlist **stack);
t_nlist		*new_node(int number);
int			list_size(t_nlist *stack);
t_nlist		*last_node(t_nlist *stack);
void		add_back(t_nlist **stack, t_nlist *node);
void		add_front(t_nlist **stack, t_nlist *node);

void		prep_stack_a(int argc, char **argv, t_nlist **stack_a);
long long	ft_atoll(const char *nptr);
void		swap(t_nlist *stack, int flag);
void		push(t_nlist **stack1, t_nlist **stack2, int flag);
void		rotate(t_nlist **stack, int flag);
void		reverse_rotate(t_nlist **stack, int flag);
long long	find_min(t_nlist *stack);
int			count_moves(t_nlist *stack, long long min);
int			check_sort(t_nlist *stack);
void		choose_sort(t_nlist **stack_a, t_nlist **stack_b);
void		sort_3(t_nlist **stack);
void		sort_4(t_nlist **stack_a, t_nlist **stack_b);
void		sort_5(t_nlist **stack_a, t_nlist **stack_b);

#endif