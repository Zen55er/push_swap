/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:17:47 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/30 12:53:42 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

# ifndef CHUNK
#  define CHUNK 20
# endif

# ifndef CHUNK500
#  define CHUNK500 45
# endif

typedef struct s_nlist
{
	int				value;
	int				position;
	struct s_nlist	*next;
	struct s_nlist	*previous;
}					t_nlist;

t_nlist		*new_node(int number);
int			list_size(t_nlist *stack);
t_nlist		*last_node(t_nlist *stack);
void		add_back(t_nlist **stack, t_nlist *node);
void		add_front(t_nlist **stack, t_nlist *node);

void		swap(t_nlist *stack, int flag);
void		push(t_nlist **stack1, t_nlist **stack2, int flag);
void		rotate(t_nlist **stack, int flag);
void		reverse_rotate(t_nlist **stack, int flag);

int			find_min(t_nlist *stack);
void		get_positions(t_nlist *stack);
int			get_min(t_nlist *stack);
int			get_max(t_nlist *stack);
int			find_min_pos_moves(t_nlist *stack, int pos);
int			find_mid_pos_moves(t_nlist *stack, int pos);
int			check_combos(t_nlist *stack_b, int moves, int moves_b);
int			test_combos(t_nlist **stack_b, int ma, int mb);
void		execute_diff(t_nlist **stack_a, t_nlist **stack_b, int ma, int mb);
void		exec_same_r(t_nlist **stack_a, t_nlist **stack_b, int ma, int mb);
void		exec_same_rr(t_nlist **stack_a, t_nlist **stack_b, int ma, int mb);

void		push_swap(int argc, char **argv);
int			count_moves(t_nlist *stack, int min);
int			check_sort(t_nlist *stack);
void		choose_sort(t_nlist **stack_a, t_nlist **stack_b);
void		sort_3(t_nlist **stack);
void		sort_5(t_nlist **stack_a, t_nlist **stack_b);
void		sort_100(t_nlist **stack_a, t_nlist **stack_b);
void		sort_500(t_nlist **stack_a, t_nlist **stack_b);

long long	ft_atoll(const char *nptr);
#endif