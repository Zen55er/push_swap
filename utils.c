/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:47:32 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/09 15:23:41 by gacorrei         ###   ########.fr       */
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

void	choose_sort(t_list **stack)
{
	int	n;

	if (check_sort(*stack) == 1)
		return ;
	n = ft_lstsize(*stack);
	if (n == 3)
		sort_3(stack);
	/* else if (n == 5)
		sort_5(stack); */
	return ;
}

void	sort_3(t_list **stack)
{
	t_list	*temp;
	int		*a;
	int		*b;
	int		*c;

	temp = *stack;
	a = (*stack)->content;
	b = (*stack)->next->content;
	c = (*stack)->next->next->content;
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
