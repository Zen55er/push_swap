/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:39:35 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/11 11:58:44 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_0(t_nlist *stack)
{
	int		min;

	min = find_min(stack);
	while (stack)
	{
		if (stack->value == min)
		{
			stack->position = 0;
			break ;
		}
		stack = stack->next;
	}
	return (min);
}

static int	find_next_min(t_nlist *stack, int min, int position)
{
	int		new_min;
	t_nlist	*temp;

	temp = stack;
	while (stack)
	{
		if (stack->position == -1)
			break ;
		stack = stack->next;
	}
	new_min = stack->value;
	while (stack)
	{
		if (stack->value < new_min && stack->value > min)
			new_min = stack->value;
		stack = stack->next;
	}
	while (temp)
	{
		if (temp->value == new_min)
			break ;
		temp = temp->next;
	}
	temp->position = position;
	return (new_min);
}

void	get_positions(t_nlist *stack)
{
	int		current_min;
	int		position;
	int		size;

	current_min = set_0(stack);
	position = 1;
	size = list_size(stack);
	while (position < size)
	{
		current_min = find_next_min(stack, current_min, position);
		position++;
	}
	return ;
}
