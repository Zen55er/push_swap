/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:30:30 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/09 15:22:18 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack, int flag)
{
	int	*i;

	i = stack->content;
	stack->content = stack->next->content;
	stack->next->content = i;
	if (flag == 0)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
	return ;
}

void	push(t_list **stack1, t_list **stack2, int flag)
{
	t_list	*temp;

	temp = *stack1;
	*stack1 = (*stack1)->next;
	temp->next = *stack2;
	*stack2 = temp;
	if (flag == 0)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
	return ;
}

void	rotate(t_list **stack, int flag)
{
	t_list	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = 0;
	ft_lstadd_back(stack, temp);
	if (flag == 0)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
	return ;
}

static void	separate(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp)
	{
		if (temp->next->next == 0)
			temp->next = 0;
		temp = temp->next;
	}
	return ;
}

void	reverse_rotate(t_list **stack, int flag)
{
	t_list	*temp;

	temp = ft_lstlast(*stack);
	separate(stack);
	ft_lstadd_front(stack, temp);
	if (flag == 0)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
	return ;
}
