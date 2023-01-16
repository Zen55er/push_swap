/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:26:17 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/16 12:28:19 by gacorrei         ###   ########.fr       */
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

static int	find_moves(t_nlist *stack_a, t_nlist *stack_b, int start, int end)
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

static void	execute_moves(t_nlist **stack_a, t_nlist **stack_b, int moves)
{
	int	current_position;

	current_position = get_current(*stack_a, moves);
	if (moves >= 0)
	{
		while (moves > 0)
		{
			rotate(stack_a, 0);
			moves--;
		}
	}
	else
	{
		while (moves < 0)
		{
			reverse_rotate(stack_a, 0);
			moves++;
		}
	}
}

void	sort_100(t_nlist **stack_a, t_nlist **stack_b)
{
	int		moves;
	int		chunk_start;
	int		chunk_end;

	chunk_start = 0;
	chunk_end = 20;
	moves = find_moves(*stack_a, *stack_b, chunk_start, chunk_end);
	execute_moves(stack_a, stack_b, moves);
}
