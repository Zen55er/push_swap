/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:30:30 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/17 10:01:15 by gacorrei         ###   ########.fr       */
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
	else if (flag == 1)
		ft_printf("sb\n");
	else if (flag == 2)
		ft_printf("ss\n");
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
	else if (flag == 1)
		ft_printf("rb\n");
	else if (flag == 2)
		ft_printf("rr\n");
	return ;
}

void	reverse_rotate(t_nlist **stack, int flag)
{
	(*stack) = (*stack)->previous;
	if (flag == 0)
		ft_printf("rra\n");
	else if (flag == 1)
		ft_printf("rrb\n");
	else if (flag == 2)
		ft_printf("rrr\n");
	return ;
}
