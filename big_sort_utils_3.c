/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:42:17 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/19 14:47:16 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_spec_r(t_nlist **stack_a, t_nlist **stack_b, int ma, int mb)
{
	if (ma >= mb)
	{
		while (mb-- != 0)
		{
			rotate(stack_b, 3);
			rotate(stack_a, 2);
			ma--;
		}
		while (ma-- != 0)
			rotate(stack_a, 0);
	}
	else
	{
		while (ma-- != 0)
		{
			rotate(stack_a, 3);
			rotate(stack_b, 2);
			mb--;
		}
		while (mb-- != 0)
			rotate(stack_b, 1);
	}
	return ;
}

static void	exec_spec_rr(t_nlist **stack_a, t_nlist **stack_b, int ma, int mb)
{
	if (ma <= mb)
	{
		while (mb++ != 0)
		{
			reverse_rotate(stack_b, 3);
			reverse_rotate(stack_a, 2);
			ma++;
		}
		while (ma++ != 0)
			reverse_rotate(stack_a, 0);
	}
	else
	{
		while (ma++ != 0)
		{
			reverse_rotate(stack_a, 3);
			reverse_rotate(stack_b, 2);
			mb++;
		}
		while (mb++ != 0)
			reverse_rotate(stack_b, 1);
	}
	return ;
}

void	exec_special(t_nlist **stack_a, t_nlist **stack_b, int ma, int mb)
{
	if ((ma >= 0 && mb >= 0))
		exec_spec_r(stack_a, stack_b, ma, mb);
	else if (ma <= 0 && mb <= 0)
		exec_spec_rr(stack_a, stack_b, ma, mb);
	push(stack_a, stack_b, 1);
	return ;
}
