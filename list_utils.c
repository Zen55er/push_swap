/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:00:59 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/10 12:56:28 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nlist	*new_node(int number)
{
	t_nlist	*node;

	node = malloc(sizeof(t_nlist));
	if (!node)
		return (0);
	node->value = number;
	node->position = -1;
	node->next = 0;
	return (node);
}

int	list_size(t_nlist *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_nlist	*last_node(t_nlist *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	add_back(t_nlist **stack, t_nlist *node)
{
	t_nlist	*temp;

	if (!*stack)
	{
		*stack = node;
		return ;
	}
	temp = last_node(*stack);
	temp->next = node;
	return ;
}

void	add_front(t_nlist **stack, t_nlist *node)
{
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	node->next = *stack;
	*stack = node;
	return ;
}
