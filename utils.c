/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:47:32 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/09 16:38:47 by gacorrei         ###   ########.fr       */
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

long long	find_min(t_list *stack)
{
	long long	min;

	min = (long long)stack->content;
	while (stack)
	{
		if ((long long)stack->content < min)
			min = (long long)stack->content;
		stack = stack->next;
	}
	return (min);
}

int	check_sort(t_list *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	choose_sort(t_list **stack_a, t_list **stack_b)
{
	int	n;

	if (check_sort(*stack_a) == 1)
		return ;
	n = ft_lstsize(*stack_a);
	if (n == 2)
		swap(*stack_a, 0);
	else if (n == 3)
		sort_3(stack_a);
	else if (n == 4)
		sort_4(stack_a, stack_b);
	/* else if (n == 5)
		sort_5(stack_a, stack_b); */
	return ;
}
