/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:11:42 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/09 11:47:59 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	del(void *content)
{
	content = 0;
	return ;
}

static int	check_value(char *test)
{
	int			i;
	long long	num;

	i = 0;
	if (test[i] == '-' && ft_isdigit(test[i + 1]))
		i++;
	if (test[i] == '0' && test[i + 1] != '\0')
		return (write(2, "Error\n", 6));
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

void	prep_stack_a(int argc, char **argv, t_list **stack_a)
{
	int		i;
	t_list	*temp;

	if (check_repeat(argc, argv) == 6)
		return ;
	i = 1;
	while (i < argc)
	{
		if (check_value(argv[i]) == 6)
		{
			ft_lstclear(stack_a, del);
			return ;
		}
		temp = ft_lstnew((void *)ft_atoll(argv[i]));
		if (!temp)
		{
			ft_lstclear(stack_a, del);
			return ;
		}
		ft_lstadd_back(stack_a, temp);
		i++;
	}
	return ;
}
