/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:13:55 by seongjch          #+#    #+#             */
/*   Updated: 2022/07/13 10:20:46 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a_to_b_sub(t_stack **a_top, t_stack **b_top, int to_push, int *pushed)
{
	int	mid;
	int	rotate_cnt;

	rotate_cnt = 0;
	*pushed = 0;
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
			(*pushed)++;
		}
		to_push--;
	}
	return (rotate_cnt++);
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
	int	*pushed;
	int	cnt;
	int	rotate_cnt;

	cnt = 0;
	pushed = malloc(sizeof(int));
	if (to_push == 1 || to_push == 0)
		return ;
	else if (to_push == 2)
	{
		little_sort(a_top);
		return ;
	}
	rotate_cnt = a_to_b_sub(a_top, b_top, to_push, pushed);
	while (rotate_cnt > cnt)
	{
		write(1, "rra\n", 4);
		reverse_rotate(a_top);
		cnt++;
	}
	a_to_b(a_top, b_top, rotate_cnt);
	b_to_a(a_top, b_top, *pushed);
	free(pushed);
}

int	b_to_a_sub(t_stack **a_top, t_stack **b_top, int pushed, int *to_push)
{
	int	mid;
	int	rotate_cnt;

	*to_push = 0;
	rotate_cnt = 0;
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
			(*to_push)++;
		}
		pushed--;
	}
	return (rotate_cnt++);
}

void	b_to_a(t_stack **a_top, t_stack **b_top, int pushed)
{
	int	rotate_cnt;
	int	cnt;
	int	*to_push;

	cnt = 0;
	to_push = malloc(sizeof(int));
	rotate_cnt = 0;
	if (pushed == 0)
		return ;
	if (pushed == 1)
	{
		write(1, "pa\n", 3);
		push(a_top, b_top);
		return ;
	}
	rotate_cnt = b_to_a_sub(a_top, b_top, pushed, to_push);
	while (rotate_cnt > cnt)
	{
		write(1, "rrb\n", 4);
		reverse_rotate(b_top);
		cnt++;
	}
	a_to_b(a_top, b_top, *to_push);
	b_to_a(a_top, b_top, rotate_cnt);
	free(to_push);
}
