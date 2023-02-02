/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:39:35 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/24 11:51:13 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_positions(t_nlist *stack)
{
	int		size;
	t_nlist	*temp;
	t_nlist	*start;

	size = list_size(stack);
	start = stack;
	temp = stack;
	while (stack->position < size - 1)
	{
		if (stack->value > temp->value)
			stack->position++;
		temp = temp->next;
		if (temp == start)
		{
			stack = stack->next;
			if (stack == start)
				break ;
		}
	}
	return ;
}
