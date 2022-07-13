/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:09:57 by seongjch          #+#    #+#             */
/*   Updated: 2022/07/13 09:16:58 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_mid(t_stack *top, int n)
{
	t_stack *sorted;
	int		len;
	int		cnt;

	sorted = malloc(sizeof(struct s_stack));
	if (!sorted)
		exit(0);
	copy(&sorted, &top, n);
	sorting(sorted);
	cnt = 0;
	len = len_stack(sorted) / 2 + 1;
	while (sorted != 0)
	{
		cnt++;
		if (cnt == len)
		{
			cnt = sorted->data;
			free(sorted);
			return (cnt);
		}
		sorted = sorted->next;
	}
	return (0);
}

int	find_min(t_stack *top)
{
	int		min;
	t_stack *list;

	list = top;
	min = 2147483647;
	while (list != 0)
	{
		if (min > list->data)
			min = list->data;
		list = list->next;
	}
	return (min);
}

int	is_min(t_stack *top, int min)
{
	t_stack *list;

	list = top;
	while (list != 0)
	{
		if (list->data < min)
			return (0);
		list = list->next;
	}
	return (1);
}

int	len_stack(t_stack	*top)
{
	t_stack *list;
	int		len;

	len = 0;
	list = top;
	while (list != 0)
	{
		len++;
		list = list->next;
	}
	return (len);
}

int	is_sort(t_stack *top, int len)
{
	t_stack *list;
	int		val;

	val = -2147483648;
	list = top;
	while (list != 0 && len > 0)
	{
		if (list->data > val)
			val = list->data;
		else
			return (0);
		len--;
		list = list->next;
	}
	return (1);
}
