/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:11:42 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/24 13:28:20 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	free_list(t_nlist **stack)
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

static int	check_repeat(int size, char **args)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (write(2, "Error\n", 6));
			j++;
		}
		i++;
	}
	return (0);
}

static void	prep_stack_a(int size, char **args, t_nlist **stack_a)
{
	int		i;
	t_nlist	*temp;

	if (check_repeat(size, args) == 6)
		return ;
	i = 1;
	while (i < size)
	{
		if (check_value(args[i]) == 6)
		{
			free_list(stack_a);
			return ;
		}
		temp = new_node(ft_atoi(args[i]));
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
	char	**args;
	int		size;
	t_nlist	*stack_a;
	t_nlist	*stack_b;

	if (argc < 2)
		return ;
	args = ft_split(argv[1], ' ');
	size = 0;
	stack_a = 0;
	stack_b = 0;
	while (args[size])
		size++;
	prep_stack_a(size, args, &stack_a);
	while (size-- > 0)
		free (args[size]);
	free (args);
	if (!stack_a)
		return ;
	get_positions(stack_a);
	choose_sort(&stack_a, &stack_b);
	free_list(&stack_a);
	free_list(&stack_b);
	return ;
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
	return (0);
}
