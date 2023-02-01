/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:39:35 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/24 11:51:13 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_0(t_nlist *stack)
{
	int		min;
	t_nlist	*temp;

	temp = stack;
	min = find_min(stack);
	while (stack)
	{
		if (stack->value == min)
		{
			stack->position = 0;
			break ;
		}
		stack = stack->next;
		if (stack == temp)
			break ;
	}
	return (min);
}

static int	next_min_set(t_nlist *stack)
{
	int		new_min;
	t_nlist	*temp;

	temp = stack;
	while (stack)
	{
		if (stack->position == -1)
			break ;
		stack = stack->next;
		if (stack == temp)
			break ;
	}
	new_min = stack->value;
	return (new_min);
}

static int	find_next_min(t_nlist *stack, int min, int position)
{
	int		new_min;
	t_nlist	*temp;

	new_min = next_min_set(stack);
	temp = stack;
	while (stack)
	{
		if (stack->value < new_min && stack->value > min)
			new_min = stack->value;
		stack = stack->next;
		if (stack == temp)
			break ;
	}
	stack = temp;
	while (stack)
	{
		if (stack->value == new_min)
			break ;
		stack = stack->next;
		if (stack == temp)
			break ;
	}
	stack->position = position;
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
