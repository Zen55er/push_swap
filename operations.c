/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:30:30 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/17 10:36:50 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_nlist *stack, int flag)
{
	int	hold_value;
	int	hold_position;

	hold_value = stack->value;
	hold_position = stack->position;
	stack->value = stack->next->value;
	stack->position = stack->next->position;
	stack->next->value = hold_value;
	stack->next->position = hold_position;
	if (flag == 0)
		write(1, "sa\n", 3);
	else if (flag == 1)
		write(1, "sb\n", 3);
	else if (flag == 2)
		write(1, "ss\n", 3);
	return ;
}

void	push(t_nlist **stack1, t_nlist **stack2, int flag)
{
	t_nlist	*temp;

	temp = *stack1;
	if ((*stack1)->next->value == temp->value)
		*stack1 = 0;
	else
	{
		*stack1 = (*stack1)->next;
		(*stack1)->previous = temp->previous;
		temp->previous->next = (*stack1);
	}
	add_front(stack2, temp);
	if (flag == 0)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
	return ;
}

void	rotate(t_nlist **stack, int flag)
{
	(*stack) = (*stack)->next;
	if (flag == 0)
		write(1, "ra\n", 3);
	else if (flag == 1)
		write(1, "rb\n", 3);
	else if (flag == 2)
		write(1, "rr\n", 3);
	return ;
}

void	reverse_rotate(t_nlist **stack, int flag)
{
	(*stack) = (*stack)->previous;
	if (flag == 0)
		write(1, "rra\n", 4);
	else if (flag == 1)
		write(1, "rrb\n", 4);
	else if (flag == 2)
		write(1, "rrr\n", 4);
	return ;
}
