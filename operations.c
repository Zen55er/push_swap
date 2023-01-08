/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:30:30 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/06 15:00:17 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack)
{
	int	*i;

	i = stack->content;
	stack->content = stack->next->content;
	stack->next->content = i;
	return ;
}

/* void	push(t_list *stack1, t_list *stack2)
{
	t_list	*temp;

	temp = stack1->next;
	stack1->next = 0;
	ft_lstadd_front(&stack2, stack1);
	stack1 = temp;
	return ;
} */

void	push(t_list **stack1, t_list **stack2)
{
	t_list	*temp;

	temp = *stack1;
	*stack1 = (*stack1)->next;
	temp->next = *stack2;
	*stack2 = temp;
	return ;
}
