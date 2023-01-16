/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:30:30 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/16 10:20:24 by gacorrei         ###   ########.fr       */
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
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
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
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
	return ;
}

void	rotate(t_nlist **stack, int flag)
{
	(*stack) = (*stack)->next;
	if (flag == 0)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
	return ;
}

void	reverse_rotate(t_nlist **stack, int flag)
{
	(*stack) = (*stack)->previous;
	if (flag == 0)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
	return ;
}
