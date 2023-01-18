/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:26:17 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/18 11:01:59 by gacorrei         ###   ########.fr       */
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

static int	find_moves(t_nlist *stack_a, int start, int end)
{
	int		moves;
	t_nlist	*temp_forward;
	t_nlist	*temp_backward;

	moves = 0;
	temp_forward = stack_a;
	temp_backward = stack_a;
	while (1)
	{
		if (temp_forward->position >= start
			&& temp_forward->position < end)
			break ;
		else if (temp_backward->position >= start
			&& temp_backward->position < end)
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

static int	test_combos(t_nlist *stack_b, int moves, int moves_b)
{
	if (moves > 0 && moves_b < 0 || moves < 0 && moves_b > 0)
	{
		if (check_combos(stack_b, moves, moves_b) != moves_b)
		{
			moves_b = check_combos(stack_b, moves, moves_b);
			if (moves < 0)
				moves_b *= -1;
		}
	}
	return (moves_b);
}

static void	execute_moves(t_nlist **stack_a, t_nlist **stack_b, int ma, int mb)
{
	int	current_position;

	current_position = get_current(*stack_a, ma);
	if (ma >= 0)
	{
		while (ma > 0)
		{
			rotate(stack_a, 0);
			ma--;
		}
	}
	else
	{
		while (ma < 0)
		{
			reverse_rotate(stack_a, 0);
			ma++;
		}
	}
}

void	sort_100(t_nlist **stack_a, t_nlist **stack_b)
{
	int		moves;
	int		moves_b;
	int		current_pos;
	int		min_pos_b;
	int		chunk_start;
	int		chunk_end;

	chunk_start = 0;
	chunk_end = 20;
	min_pos_b = find_min_pos(*stack_b);
	moves = find_moves(*stack_a, chunk_start, chunk_end);
	current_pos = get_current(*stack_a, moves);
	if (current_pos > find_max_pos(*stack_b)
		|| current_pos < min_pos_b)
		moves_b = find_min_pos_moves(*stack_b, min_pos_b);
	else
		moves_b = find_mid_pos_moves(*stack_b, current_pos);
	moves_b = test_combos(*stack_b, moves, moves_b);
	execute_moves(stack_a, stack_b, moves, moves_b);
}
