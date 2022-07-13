/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:13:55 by seongjch          #+#    #+#             */
/*   Updated: 2022/07/13 09:22:45 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void a_to_b(t_stack **a_top, t_stack **b_top, int to_push)
{
	int	rotate_cnt;
	int	mid;
	int	pushed;
	int	cnt;

	cnt = 0;
	pushed = 0;
	rotate_cnt = 0;
	if (to_push == 1 || to_push == 0)
		return ;
	else if (to_push == 2)
	{
		if (!is_sort(*a_top, 2))
		{
			write(1, "sa\n", 3);
			swap(*a_top);

		}
		return ;
	}
	mid = find_mid(*a_top, to_push);
	while (to_push)
	{
		if ((*a_top)->data > mid)
		{
			write(1, "ra\n", 3);
			rotate(a_top);

			rotate_cnt++;
		}
		else
		{
			write(1, "pb\n", 3);
			push(b_top, a_top);

			pushed++;
		}
		to_push--;
	}
	while (rotate_cnt > cnt)
	{
		write(1, "rra\n", 4);
		reverse_rotate(a_top);

		cnt++;
	}
	a_to_b(a_top, b_top, rotate_cnt);
	b_to_a(a_top, b_top, pushed);
}

void b_to_a(t_stack **a_top, t_stack **b_top, int pushed)
{
	int	mid;
	int	rotate_cnt;
	int	cnt;
	int	to_push;

	to_push = 0;
	cnt	= 0;
	rotate_cnt = 0;
	if (pushed == 0)
		return ;
	if (pushed == 1)
	{
		write(1, "pa\n", 3);
		push(a_top, b_top);

		return ;
	}
	mid = find_mid(*b_top, pushed);
	while (pushed)
	{
		if ((*b_top)->data < mid)
		{
			write(1, "rb\n", 3);
			rotate(b_top);
			rotate_cnt++;
		}
		else
		{
			write(1, "pa\n", 3);
			push(a_top, b_top);
			to_push++;
		}
		pushed--;
	}
	while (rotate_cnt > cnt)
	{
		write(1, "rrb\n", 4);
		reverse_rotate(b_top);
		cnt++;
	}
	a_to_b(a_top, b_top, to_push);
	b_to_a(a_top, b_top, rotate_cnt);
}
