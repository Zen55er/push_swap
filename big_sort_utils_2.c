/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:33:29 by gacorrei          #+#    #+#             */
/*   Updated: 2023/01/19 16:10:37 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_diff(t_nlist **stack_a, t_nlist **stack_b, int ma, int mb)
{
	if (ma > 0)
	{
		while (ma-- > 0)
			rotate(stack_a, 0);
	}
	else
	{
		while (ma++ < 0)
			reverse_rotate(stack_a, 0);
	}
	if (mb > 0)
	{
		while (mb-- > 0)
			rotate(stack_b, 1);
	}
	else
	{
		while (mb++ < 0)
			reverse_rotate(stack_b, 1);
	}
	return ;
}

void	exec_same_r(t_nlist **stack_a, t_nlist **stack_b, int ma, int mb)
{
	if (ma >= mb)
	{
		while (mb-- > 0)
		{
			rotate(stack_b, 3);
			rotate(stack_a, 2);
			ma--;
		}
		while (ma-- > 0)
			rotate(stack_a, 0);
	}
	else
	{
		while (ma-- > 0)
		{
			rotate(stack_a, 3);
			rotate(stack_b, 2);
			mb--;
		}
		while (mb-- > 0)
			rotate(stack_b, 1);
	}
	return ;
}

void	exec_same_rr(t_nlist **stack_a, t_nlist **stack_b, int ma, int mb)
{
	if (ma <= mb)
	{
		while (mb++ < 0)
		{
			reverse_rotate(stack_b, 3);
			reverse_rotate(stack_a, 2);
			ma++;
		}
		while (ma++ < 0)
			reverse_rotate(stack_a, 0);
	}
	else
	{
		while (ma++ < 0)
		{
			reverse_rotate(stack_a, 3);
			reverse_rotate(stack_b, 2);
			mb++;
		}
		while (mb++ < 0)
			reverse_rotate(stack_b, 1);
	}
	return ;
}

int	check_combos(t_nlist *stack_b, int moves_a, int moves_b)
{
	int	new_moves;
	int	total;
	int	test;
	int	signal_check;

	signal_check = 1;
	if (moves_b < 0)
	{
		moves_b *= -1;
		signal_check = -1;
	}
	if (moves_a < 0)
		moves_a *= -1;
	total = moves_a + moves_b;
	new_moves = list_size(stack_b) - moves_b;
	if (moves_a >= new_moves)
		test = 0;
	else
		test = new_moves - moves_a;
	if (moves_a + test < total)
		return (new_moves);
	else
		return (moves_b * signal_check);
}

int	test_combos(t_nlist **stack_b, int ma, int mb)
{
	if ((ma > 0 && mb < 0) || (ma < 0 && mb > 0))
	{
		if (check_combos(*stack_b, ma, mb) != mb)
		{
			mb = check_combos(*stack_b, ma, mb);
			if (ma < 0)
				mb *= -1;
		}
	}
	return (mb);
}
