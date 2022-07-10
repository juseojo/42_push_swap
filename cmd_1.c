/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:29:35 by seongjch          #+#    #+#             */
/*   Updated: 2022/07/10 21:55:27 by seongjch         ###   ########.fr       */
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

int	find_min(t_stack **top)
{
	int		min;
	t_stack *list;

	list = *top;
	min = 2147483647;
	while (list != 0)
	{
		if (min > list->data)
			min = list->data;
		list = list->next;
	}
	return (min);
}

void	sorting(t_stack **top)
{
	t_stack *list;
	t_stack *sorted_node;
	int		min;

	sorted_node = *top;
	while (sorted_node != 0)
	{
		list = sorted_node;
		min = find_min(&list);
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

int find_middle(t_stack	**top)
{
	t_stack *list;
	int		len;
	int		cnt;

	len = 0;
	cnt = 0;
	list = *top;
	while (list != 0)
	{
		len++;
		list = list->next;
	}
	len = len / 2;
	while (list != 0)
	{
		cnt++;
		if (cnt == len)
			return (list->data);
		list = list->next;
	}
	return (0);
}

int main()
{
	t_stack	*top;
	t_stack	*top2;
	t_stack *sorted;

	top = 0;
	append(&top, 3);
	append(&top, 2);
	append(&top, -4);
	append(&top, 1);
	append(&top2, 6);
	append(&top2, 5);
	append(&top2, 4);
	sorted = malloc(sizeof(struct s_stack));
	copy(&sorted, &top);
	sorting(&sorted);
	while (sorted != 0)
	{
		printf("%d\n", sorted->data);
		sorted = sorted->next;
	}
}
