/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:00:59 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/12 13:53:09 by gacorrei         ###   ########.fr       */
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
	node->previous = 0;
	return (node);
}

int	list_size(t_nlist *stack)
{
	int		size;
	t_nlist	*temp;

	size = 0;
	temp = stack;
	while (stack)
	{
		size++;
		stack = stack->next;
		if (stack == temp)
			break ;
	}
	return (size);
}

t_nlist	*last_node(t_nlist *stack)
{
	if (stack->previous)
		return (stack->previous);
	else
		return (stack);
}

void	add_back(t_nlist **stack, t_nlist *node)
{
	t_nlist	*temp;

	if (!*stack)
	{
		*stack = node;
		node->next = node;
		node->previous = node;
		return ;
	}
	temp = (*stack)->previous;
	temp->next = node;
	(*stack)->previous = node;
	node->next = (*stack);
	node->previous = temp;
	return ;
}

void	add_front(t_nlist **stack, t_nlist *node)
{
	if (!*stack)
	{
		*stack = node;
		node->next = node;
		node->previous = node;
		return ;
	}
	add_back(stack, node);
	*stack = node;
	return ;
}
