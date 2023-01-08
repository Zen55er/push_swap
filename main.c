/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:41:54 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/06 14:49:00 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	del(void *content)
{
	content = 0;
	return ;
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*temp_a;
	t_list	*temp_b;

	i = 1;
	stack_a = 0;
	stack_b = 0;
	/* ft_printf("BEFORE:\n");
	while (i < argc)
	{
		ft_printf("%s\n", argv[i]);
		i++;
	} */
	stack_a = prep_stack_a(argc, argv, stack_a);
	temp_a = stack_a;
	while (temp_a)
	{
		printf("Stack A, Node %i content: %lld\n", i, (long long)temp_a->content);
		temp_a = temp_a->next;
		i++;
	}
	swap(stack_a);
	i = 1;
	ft_printf("\nTESTING SWAP\n");
	temp_a = stack_a;
	while (temp_a)
	{
		printf("Stack A, Node %i content: %lld\n", i, (long long)temp_a->content);
		temp_a = temp_a->next;
		i++;
	}
	temp_b = stack_b;
	i = 1;
	ft_printf("\nTESTING EMPTY B\n");
	while (temp_b)
	{
		printf("Stack B, Node %i content: %lld\n", i, (long long)temp_b->content);
		temp_b = temp_b->next;
		i++;
	}
	push(&stack_a, &stack_b);
	temp_a = stack_a;
	temp_b = stack_b;
	i = 1;
	ft_printf("\nTESTING PUSH\n");
	while (temp_a)
	{
		printf("Stack A, Node %i content: %lld\t\t\t", i, (long long)temp_a->content);
		if (temp_b)
		{
			printf("Stack B, Node %i content: %lld\n", i, (long long)temp_b->content);
			temp_b = temp_b->next;
		}
		else
			printf("\n");
		temp_a = temp_a->next;
		i++;
	}
	ft_lstclear(&stack_a, del);
	ft_lstclear(&stack_b, del);
	return (0);
}
