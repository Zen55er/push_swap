/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_swap_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:33:29 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/18 12:02:09 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_diff(t_nlist **stack_a, t_nlist **stack_b, int ma, int mb)
{
	if (ma > 0)
	{
		while (ma-- != 0)
			rotate(stack_a, 0);
	}
	else
	{
		while (ma++ != 0)
			reverse_rotate(stack_a, 0);
	}
	if (mb > 0)
	{
		while (mb-- != 0)
			rotate(stack_b, 1);
	}
	else
	{
		while (mb++ != 0)
			reverse_rotate(stack_b, 1);
	}
	return ;
}

void	execute_same(t_nlist **stack_a, t_nlist **stack_b, int ma, int mb)
{
	if (ma > 0 || mb > 0)
	{
		
	}
	else if (ma < 0 || mb < 0)
	{
		
	}
	return ;
}
