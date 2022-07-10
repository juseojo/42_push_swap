/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:29:35 by seongjch          #+#    #+#             */
/*   Updated: 2022/07/11 02:16:59 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	swap(t_stack	**top)
{
	int	temp;

	temp = (*top)->data;
	(*top)->data = (*top)->next->data;
	(*top)->next->data = temp;
}

void	push(t_stack	**dest, t_stack	**src)
{
	t_stack *for_free;

	if (src != 0)
	{
		append(dest, (*src)->data);
		for_free = *src;
		*src = (*src)->next;
		free(for_free);
	}
}

void	append(t_stack **top, int new_data)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(struct s_stack));
	if (!new_node)
		exit (0);
	new_node -> data = new_data;
	new_node -> next = *top;
	*top = new_node;
}

void	rotate(t_stack **top)
{
	t_stack *list;
	t_stack *new_top;

	list = *top;
	new_top = (*top)->next;
	while (list->next != 0)
		list = list->next;
	list -> next = *top;
	(*top)-> next = 0;
	*top = new_top;
}

void	reverse_rotate(t_stack **top)
{
	t_stack *list;

	list = *top;
	while (list -> next -> next != 0)
		list = list -> next;
	append(top, list->next->data);
	free(list -> next);
	list -> next = 0;
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

void	sorting(t_stack *top)
{
	t_stack *list;
	t_stack *sorted_node;
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

void copy(t_stack **dest, t_stack **src)
{
	t_stack *list;
	t_stack *src_list;

	list = *dest;
	src_list = *src;
	while (src_list->next != 0)
	{
		list->next = malloc(sizeof(struct s_stack));
		list->data = src_list->data;
		list = list->next;
		src_list = src_list->next;
	}
	list->data = src_list->data;
	list->next = 0;
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

int find_mid(t_stack	*top)
{
	t_stack *sorted;
	int		len;
	int		cnt;

	sorted = malloc(sizeof(struct s_stack));
	if (!sorted)
		exit(0);
	copy(&sorted, &top);
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

void quick(t_stack **sorting_top, t_stack **box_top, int mid, int flag)
{
	t_stack *logic_box;

	logic_box = 0;
	while (!is_min(*sorting_top, mid))
	{
		if (flag == 0)
		{
			if ((*sorting_top)->data >= mid)
				rotate(sorting_top);
			else
				push(&logic_box, sorting_top);
		}
		if (flag == 1)
		{
			if ((*sorting_top)->data <= mid)
				rotate(sorting_top);
			else
				push(&logic_box, sorting_top);
		}
	}
	if (!is_sort(*sorting_top))
		quick(sorting_top, &logic_box, find_mid(*sorting_top), 0);
	if (!is_revers_sort(logic_box))
		quick(&logic_box, sorting_top, find_mid(logic_box), 1);
	while (logic_box != 0)
		push(sorting_top, &logic_box);
}

int	is_sort(t_stack *top)
{
	t_stack *list;
	int		val;

	val = -2147483648;
	list = top;
	while (list != 0)
	{
		if (list->data > val)
			val = list->data;
		else
			return (0);
		list = list->next;
	}
	return (1);
}

int	is_revers_sort(t_stack *top)
{
	t_stack *list;
	int		val;

	val = 2147483647;
	list = top;
	while (list != 0)
	{
		if (list->data < val)
			val = list->data;
		else
			return (0);
		list = list->next;
	}
	return (1);
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

int main()
{
	t_stack	*top;
	t_stack	*top2;
	int		mid;

	top = 0;
	append(&top, 6);
	append(&top, 7);
	append(&top, 2);
	append(&top, 5);
	append(&top, 1);
	append(&top, 8);
	append(&top, 3);
	append(&top, 4);
	top2 = 0;
	mid = find_mid(top);
	quick(&top,&top2, mid, 0);
	while (top != 0)
	{
		printf("%d\n", top->data);
		top = top->next;
	}
	printf("----------------\n");
	/*
	while (top2 != 0)
	{
		printf("%d\n", top2->data);
		top2 = top2->next;
	}
	*/
}
