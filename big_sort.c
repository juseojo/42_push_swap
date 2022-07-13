/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:13:55 by seongjch          #+#    #+#             */
/*   Updated: 2022/07/13 11:49:27 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_val	a_to_b_sub(t_stack **a_top, t_stack **b_top, t_val v)
{
	int	mid;

	v.rotate_cnt = 0;
	v.pushed = 0;
	mid = find_mid(*a_top, v.to_push);
	while (v.to_push)
	{
		if ((*a_top)->data > mid)
		{
			write(1, "ra\n", 3);
			rotate(a_top);
			v.rotate_cnt++;
		}
		else
		{
			write(1, "pb\n", 3);
			push(b_top, a_top);
			v.pushed++;
		}
		v.to_push--;
	}
	return (v);
}

void	little_sort(t_stack **a_top)
{
	if (!is_sort(*a_top, 2))
	{
		write(1, "sa\n", 3);
		swap(*a_top);
	}
}

void	a_to_b(t_stack **a_top, t_stack **b_top, int to_push)
{
	int		cnt;
	t_val	v;

	cnt = 0;
	v.pushed = 0;
	v.to_push = to_push;
	if (to_push == 1 || to_push == 0)
		return ;
	else if (to_push == 2)
	{
		little_sort(a_top);
		return ;
	}
	v = a_to_b_sub(a_top, b_top, v);
	while (v.rotate_cnt > cnt)
	{
		write(1, "rra\n", 4);
		reverse_rotate(a_top);
		cnt++;
	}
	a_to_b(a_top, b_top, v.rotate_cnt);
	b_to_a(a_top, b_top, v.pushed);
}

t_val	b_to_a_sub(t_stack **a_top, t_stack **b_top, t_val v)
{
	int	mid;

	v.rotate_cnt = 0;
	v.to_push = 0;
	mid = find_mid(*b_top, v.pushed);
	while (v.pushed)
	{
		if ((*b_top)->data < mid)
		{
			write(1, "rb\n", 3);
			rotate(b_top);
			v.rotate_cnt++;
		}
		else
		{
			write(1, "pa\n", 3);
			push(a_top, b_top);
			v.to_push++;
		}
		v.pushed--;
	}
	return (v);
}

void	b_to_a(t_stack **a_top, t_stack **b_top, int pushed)
{
	int		cnt;
	t_val	v;

	cnt = 0;
	v.pushed = pushed;
	v.to_push = 0;
	if (v.pushed == 0)
		return ;
	if (v.pushed == 1)
	{
		write(1, "pa\n", 3);
		push(a_top, b_top);
		return ;
	}
	v = b_to_a_sub(a_top, b_top, v);
	while (v.rotate_cnt > cnt)
	{
		write(1, "rrb\n", 4);
		reverse_rotate(b_top);
		cnt++;
	}
	a_to_b(a_top, b_top, v.to_push);
	b_to_a(a_top, b_top, v.rotate_cnt);
}
