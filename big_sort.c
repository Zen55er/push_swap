/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:26:17 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/19 09:33:07 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_current(t_nlist *stack_a, int moves)
{
	t_nlist	*temp_forward;
	t_nlist	*temp_backward;

	temp_forward = stack_a;
	temp_backward = stack_a;
	if (moves >= 0)
	{
		while (moves > 0)
		{
			temp_forward = temp_forward->next;
			moves--;
		}
		return (temp_forward->position);
	}
	else
	{
		while (moves < 0)
		{
			temp_backward = temp_backward->previous;
			moves++;
		}
		return (temp_backward->position);
	}
}

static int	find_moves(t_nlist *stack_a, int end)
{
	int		moves;
	t_nlist	*temp_forward;
	t_nlist	*temp_backward;

	moves = 0;
	temp_forward = stack_a;
	temp_backward = stack_a;
	while (1)
	{
		if (temp_forward->position < end)
			break ;
		else if (temp_backward->position < end)
		{
			moves *= -1;
			break ;
		}
		moves++;
		temp_forward = temp_forward->next;
		if (temp_forward->value == stack_a->value)
			break ;
		temp_backward = temp_backward->previous;
	}
	return (moves);
}

static int	test_combos(t_nlist *stack_b, int moves_a, int moves_b)
{
	if ((moves_a > 0 && moves_b < 0) || (moves_a < 0 && moves_b > 0))
	{
		if (check_combos(stack_b, moves_a, moves_b) != moves_b)
		{
			moves_b = check_combos(stack_b, moves_a, moves_b);
			if (moves_a < 0)
				moves_b *= -1;
		}
	}
	return (moves_b);
}

static void	execute_moves(t_nlist **stack_a, t_nlist **stack_b, int ma, int mb)
{
	if ((ma >= 0 && mb <= 0) || (ma <= 0 && mb >= 0))
		execute_diff(stack_a, stack_b, ma, mb);
	else if ((ma >= 0 && mb >= 0))
		exec_same_r(stack_a, stack_b, ma, mb);
	else if (ma <= 0 && mb <= 0)
		exec_same_rr(stack_a, stack_b, ma, mb);
	push(stack_a, stack_b, 1);
	return ;
}

void	sort_100(t_nlist **stack_a, t_nlist **stack_b)
{
	int		moves_a;
	int		moves_b;
	int		current_pos;
	int		min_pos_b;
	int		i;

	i = 0;
	while (i < CHUNK)
	{
		moves_a = find_moves(*stack_a, CHUNK);
		min_pos_b = find_min_pos(*stack_b);
		current_pos = get_current(*stack_a, moves_a);
		if (current_pos >= find_max_pos(*stack_b)
			|| current_pos <= min_pos_b)
			moves_b = find_min_pos_moves(*stack_b, find_max_pos(*stack_b));
		else
			moves_b = find_mid_pos_moves(*stack_b, current_pos);
		moves_b = test_combos(*stack_b, moves_a, moves_b);
		execute_moves(stack_a, stack_b, moves_a, moves_b);
		i++;
	}
}
