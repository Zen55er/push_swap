/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:17:47 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/09 16:32:34 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

void		prep_stack_a(int argc, char **argv, t_list **stack_a);
long long	ft_atoll(const char *nptr);
void		swap(t_list *stack, int flag);
void		push(t_list **stack1, t_list **stack2, int flag);
void		rotate(t_list **stack, int flag);
void		reverse_rotate(t_list **stack, int flag);
long long	find_min(t_list *stack);
int			count_moves(t_list *stack, long long min);
int			check_sort(t_list *stack);
void		choose_sort(t_list **stack_a, t_list **stack_b);
void		sort_3(t_list **stack);

#endif