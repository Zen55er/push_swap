/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_swap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:12:43 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/17 12:57:23 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_nlist *stack)
{
	int		min_pos;
	t_nlist	*temp;

	temp = stack;
	min_pos = stack->position;
	while (stack)
	{
		if (stack->position < min_pos)
			min_pos = stack->position;
		stack = stack->next;
		if (stack == temp)
			break ;
	}
	return (min_pos);
}

int	find_max_pos(t_nlist *stack)
{
	int		max_pos;
	t_nlist	*temp;

	temp = stack;
	max_pos = stack->position;
	while (stack)
	{
		if (stack->position > max_pos)
			max_pos = stack->position;
		stack = stack->next;
		if (stack == temp)
			break ;
	}
	return (max_pos);
}

int	find_min_pos_moves(t_nlist *stack, int pos)
{
	int		moves;
	t_nlist	*temp_forward;
	t_nlist	*temp_backward;

	moves = 0;
	temp_forward = stack;
	temp_backward = stack;
	while (1)
	{
		if (temp_forward->position == pos)
			break ;
		else if (temp_backward->position == pos)
		{
			moves *= -1;
			break ;
		}
		moves++;
		temp_forward = temp_forward->next;
		if (temp_forward->value == stack->value)
			break ;
		temp_backward = temp_backward->previous;
	}
	return (moves);
}

int	find_mid_pos_moves(t_nlist *stack, int pos)
{
	int		moves;
	t_nlist	*temp_forward;
	t_nlist	*temp_backward;

	moves = 0;
	temp_forward = stack;
	temp_backward = stack;
	while (1)
	{
		if (temp_forward->position > pos
			&& temp_forward->previous->position < pos)
			break ;
		else if (temp_backward->position > pos
			&& temp_backward->previous->position < pos)
		{
			moves *= -1;
			break ;
		}
		moves++;
		temp_forward = temp_forward->next;
		if (temp_forward->value == stack->value)
			break ;
		temp_backward = temp_backward->previous;
	}
	return (moves);
}
