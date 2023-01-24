/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:47:32 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/24 11:49:15 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoll(const char *nptr)
{
	int			i;
	long long	signal;
	long long	final;

	i = 0;
	signal = 1;
	final = 0;
	while (nptr[i] == 32 || (nptr[i] > 8 && nptr[i] < 14))
	{
		i++;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
		{
			signal *= -1;
		}
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		final = final * 10 + (nptr[i] - '0');
		i++;
	}
	return (final * signal);
}

int	find_min(t_nlist *stack)
{
	int		min;
	t_nlist	*temp;

	temp = stack;
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
		if (stack == temp)
			break ;
	}
	return (min);
}

int	count_moves(t_nlist *stack, int min)
{
	int		moves;
	t_nlist	*temp;

	temp = stack;
	moves = 0;
	while (stack)
	{
		if (stack->value == min)
			break ;
		moves++;
		stack = stack->next;
		if (stack == temp)
			break ;
	}
	return (moves);
}

int	check_sort(t_nlist *stack)
{
	t_nlist	*temp;

	temp = stack;
	while (stack)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
		if (stack->next->value == temp->value)
			break ;
	}
	return (1);
}

void	choose_sort(t_nlist **stack_a, t_nlist **stack_b)
{
	int	n;
	int	fix_moves;

	if (check_sort(*stack_a) == 1)
		return ;
	n = list_size(*stack_a);
	if (n == 2)
		swap(*stack_a, 0);
	else if (n == 3)
		sort_3(stack_a);
	else if (n <= 5)
		sort_5(stack_a, stack_b);
	else if (n <= 100)
		sort_100(stack_a, stack_b);
	else if (n <= 500)
		sort_500(stack_a, stack_b);
	fix_moves = find_min_pos_moves(*stack_b, list_size(*stack_b) - 1);
	execute_diff(0, stack_b, 0, fix_moves);
	while (*stack_b)
		push(stack_b, stack_a, 0);
	return ;
}
