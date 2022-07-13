/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:08:47 by seongjch          #+#    #+#             */
/*   Updated: 2022/07/13 10:26:17 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stack *top)
{
	t_stack	*list;
	t_stack	*sorted_node;
	int		min;

	sorted_node = top;
	while (sorted_node != 0)
	{
		list = sorted_node;
		min = find_min(list);
		while (list != 0)
		{
			if (min == list->data)
			{
				list->data = (sorted_node)->data;
				(sorted_node)->data = min;
				break ;
			}
			list = list->next;
		}
		sorted_node = sorted_node->next;
	}
}

void	copy(t_stack **dest, t_stack **src, int n)
{
	t_stack	*list;
	t_stack	*src_list;

	list = *dest;
	src_list = *src;
	while (src_list->next != 0 && n > 1)
	{
		list->next = malloc(sizeof(struct s_stack));
		list->data = src_list->data;
		list = list->next;
		src_list = src_list->next;
		n--;
	}
	list->data = src_list->data;
	list->next = 0;
}

void	sort_5(t_stack **a, t_stack **b)
{
	int		min;
	int		i;

	i = 0;
	while (i < 2)
	{
		min = find_min(*a);
		if ((*a)->data == min)
		{
			write(1, "pb\n", 3);
			push(b, a);
			i++;
			continue ;
		}
		write(1, "ra\n", 3);
		rotate(a);
	}
	sort_3(a);
	write(1, "pa\n", 3);
	push(a, b);
	write(1, "pa\n", 3);
	push(a, b);
}

void	sort_3_sub(t_stack **a, t_stack *list, int val, int checker)
{
	if (checker == 0)
	{
		if (val > list->data)
		{
			write(1, "sa\n", 3);
			swap(*a);
		}
		else
		{
			write(1, "rra\n", 4);
			reverse_rotate(a);
		}
	}
	else
	{
		write(1, "ra\n", 3);
		rotate(a);
		if (!is_sort(*a, 2))
		{
			write(1, "sa\n", 3);
			swap(*a);
		}
	}
}

void	sort_3(t_stack **a)
{
	int		val;
	int		checker;
	t_stack	*list;

	checker = 0;
	val = (*a)->data;
	list = (*a)->next;
	while (list != 0)
	{
		if (val < list->data)
			checker--;
		else if (val > list-> data)
			checker++;
		list = list->next;
	}
	list = (*a)->next;
	if (checker < 0)
	{
		write(1, "rra\n", 5);
		reverse_rotate(a);
		write(1, "sa\n", 4);
		swap(*a);
	}
	else
		sort_3_sub(a, list, val, checker);
}
