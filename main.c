/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:41:54 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/11 13:42:20 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	print_stack(int ac, char **av, t_nlist *stack_a, t_nlist *stack_b)
{
	int		i;
	char	c;

	i = 1;
	ft_printf("Stack A\t\t\t\t");
	if (stack_b)
		ft_printf("Stack B");
	while (stack_a)
	{
		ft_printf("\n");
		ft_printf("Node %i: %i\t\t\t", i, stack_a->value);
		if (stack_b)
		{
			ft_printf("Node %i: %i", i, stack_b->value);
			stack_b = stack_b->next;
		}
		stack_a = stack_a->next;
		i++;
	}
	ft_printf("\n");
	return ;
}

static void	print_list_info(t_nlist *stack_a)
{
	int		i;
	int		j;
	int		k;
	char	c;

	i = 1;
	ft_printf("Stack A\n");
	while (stack_a)
	{
		j = stack_a->value;
		k = stack_a->position;
		ft_printf("Node %i: Value %i\t\tPosition %i\n", i, j, k);
		stack_a = stack_a->next;
		i++;
	}
	ft_printf("\n");
	return ;
}

int	main(int argc, char **argv)
{
	t_nlist	*stack_a;
	t_nlist	*stack_b;

	stack_a = 0;
	stack_b = 0;
	/* //Print initial data
	print_start(argc, argv); */

	//Check data, passes to linked list and prints content
	prep_stack_a(argc, argv, &stack_a);
	if (!stack_a)
		return (0);
	get_positions(stack_a);
	print_list_info(stack_a);

	/* //Prints B stack to make sure it's empty
	ft_printf("\nTESTING EMPTY B\n");
	print_stack(argc, argv, 0, stack_b); */

	/* //Testing swap operation and print results
	swap(&stack_a, 0);
	ft_printf("\nTESTING SWAP\n");
	print_stack(argc, argv, stack_a, 0); */

	/* //Testing push operation and print results
	push(&stack_a, &stack_b, 1);
	ft_printf("\nTESTING PUSH\n");
	print_stack(argc, argv, stack_a, stack_b); */
	
	/* //Testing rotate operation and print results
	rotate(&stack_a, 0);
	ft_printf("\nTESTING ROTATE\n");
	print_stack(argc, argv, stack_a, stack_b); */
	
	/* //Testing reverse rotate operation and print results
	reverse_rotate(&stack_a, 0);
	ft_printf("\nTESTING REVERSE ROTATE\n");
	print_stack(argc, argv, stack_a, stack_b); */

	//Testing sorts and print results
	/* ft_printf("\nTESTING SORTS\n");
	choose_sort(&stack_a, &stack_b);
	ft_printf("\n");
	print_stack(argc, argv, stack_a, stack_b); */
	//Free memory
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}
