/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:41:54 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/09 12:34:14 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	del(void *content)
{
	content = 0;
	return ;
}

static void	print_start(int argc, char **argv)
{
	int	i;

	i = 1;
	ft_printf("Input\n");
	while (i < argc)
	{
		ft_printf("%s\n", argv[i]);
		i++;
	}
	ft_printf("\n");
	return ;
}

static void	print_stack(int ac, char **av, t_list *stack_a, t_list *stack_b)
{
	int		i;
	char	c;

	i = 1;
	printf("Stack A\t\t\t\t");
	if (stack_b)
		printf("Stack B");
	while (stack_a)
	{
		printf("\n");
		printf("Node %i: %lld\t\t\t", i, (long long)stack_a->content);
		if (stack_b)
		{
			printf("Node %i: %lld", i, (long long)stack_b->content);
			stack_b = stack_b->next;
		}
		stack_a = stack_a->next;
		i++;
	}
	printf("\n");
	return ;
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = 0;
	stack_b = 0;
	//Print initial data
	print_start(argc, argv);
	//Check data, passes to linked list and prints content
	prep_stack_a(argc, argv, &stack_a);
	print_stack(argc, argv, stack_a, 0);
	//Testing swap operation and print results
	swap(stack_a);
	ft_printf("\nTESTING SWAP\n");
	print_stack(argc, argv, stack_a, 0);
	//Prints B stack to make sure it's empty
	ft_printf("\nTESTING EMPTY B\n");
	print_stack(argc, argv, 0, stack_b);
	//Testing push operation and print results
	push(&stack_a, &stack_b);
	ft_printf("\nTESTING PUSH\n");
	print_stack(argc, argv, stack_a, stack_b);
	//Testing rotate operation and print results
	rotate(&stack_a);
	ft_printf("\nTESTING ROTATE\n");
	print_stack(argc, argv, stack_a, stack_b);
	//Testing reverse rotate operation and print results
	reverse_rotate(&stack_a);
	ft_printf("\nTESTING REVERSE ROTATE\n");
	print_stack(argc, argv, stack_a, stack_b);
	//Free memory
	ft_lstclear(&stack_a, del);
	ft_lstclear(&stack_b, del);
	return (0);
}
