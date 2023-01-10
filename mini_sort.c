/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:55:44 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/10 13:03:21 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_nlist **stack)
{
	t_nlist	*temp;
	int		*a;
	int		*b;
	int		*c;

	temp = *stack;
	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a < b && c > a)
	{
		swap(*stack, 0);
		rotate(stack, 0);
	}
	else if (a > b && c > a)
		swap(*stack, 0);
	else if (b > a && a > c)
		reverse_rotate(stack, 0);
	else if (a > b && b < c)
		rotate(stack, 0);
	else if (a > b && b > c)
	{
		swap(*stack, 0);
		reverse_rotate(stack, 0);
	}
}

void	sort_4(t_nlist **stack_a, t_nlist **stack_b)
{
	t_nlist		*temp;
	long long	min;
	long long	moves;

	min = find_min(*stack_a);
	temp = *stack_a;
	moves = count_moves(*stack_a, min);
	if (moves < 3)
	{
		while (moves > 0)
		{
			rotate(stack_a, 0);
			moves--;
		}
	}
	else
		reverse_rotate(stack_a, 0);
	push(stack_a, stack_b, 1);
	sort_3(stack_a);
	push(stack_b, stack_a, 0);
}

void	sort_5(t_nlist **stack_a, t_nlist **stack_b)
{
	t_nlist		*temp;
	long long	min;
	long long	moves;

	min = find_min(*stack_a);
	temp = *stack_a;
	moves = count_moves(*stack_a, min);
	if (moves < 3)
	{
		while (moves-- > 0)
			rotate(stack_a, 0);
	}
	else
	{
		while ((long long)(*stack_a)->value != min)
			reverse_rotate(stack_a, 0);
	}
	push(stack_a, stack_b, 1);
	sort_4(stack_a, stack_b);
	push(stack_b, stack_a, 0);
}
