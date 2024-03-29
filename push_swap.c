/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:11:42 by gacorrei          #+#    #+#             */
/*   Updated: 2023/02/01 10:29:55 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_list(t_nlist **stack)
{
	t_nlist	*temp;

	while (*stack)
	{
		temp = *stack;
		if ((*stack)->next == temp)
			(*stack) = 0;
		else
			*stack = (*stack)->next;
		if (temp->next)
		{
			temp->next->previous = 0;
			temp->next = 0;
		}
		if (temp->previous)
		{
			temp->previous->next = 0;
			temp->previous = 0;
		}
		free(temp);
	}
	return ;
}

static int	check_value(char *test)
{
	int			i;
	long long	num;

	i = 0;
	if (test[i] == '-' && ft_isdigit(test[i + 1]))
		i++;
	while (test[i])
	{
		if (!ft_isdigit(test[i]))
			return (write(2, "Error\n", 6));
		i++;
	}
	num = ft_atoll(test);
	if (num > INT_MAX || num < INT_MIN)
		return (write(2, "Error\n", 6));
	return (1);
}

static int	check_repeat(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < i)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (write(2, "Error\n", 6));
			j++;
		}
		i++;
	}
	return (0);
}

static void	prep_stack_a(int argc, char **argv, t_nlist **stack_a)
{
	int		i;
	t_nlist	*temp;

	if (check_repeat(argc, argv) == 6)
		return ;
	i = 1;
	while (i < argc)
	{
		if (check_value(argv[i]) == 6)
		{
			free_list(stack_a);
			return ;
		}
		temp = new_node(ft_atoi(argv[i]));
		if (!temp)
		{
			free_list(stack_a);
			return ;
		}
		add_back(stack_a, temp);
		i++;
	}
	return ;
}

void	push_swap(int argc, char **argv)
{
	t_nlist	*stack_a;
	t_nlist	*stack_b;

	if (argc < 2)
		return ;
	stack_a = 0;
	stack_b = 0;
	prep_stack_a(argc, argv, &stack_a);
	if (!stack_a)
		return ;
	get_positions(stack_a);
	choose_sort(&stack_a, &stack_b);
	free_list(&stack_a);
	free_list(&stack_b);
	return ;
}
