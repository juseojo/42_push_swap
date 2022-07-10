/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:29:35 by seongjch          #+#    #+#             */
/*   Updated: 2022/07/10 15:57:31 by seongjch         ###   ########.fr       */
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

void	sorting(t_stack **top)
{
	t_stack *list;
	t_stack *sorted_node;
	int		min;

	sorted_node = *top;
	while (sorted_node != 0)
	{
		min = 2147483647;
		list = sorted_node;
		
		while (list != 0)
		{
			if (min > list->data)
				min = list->data;
			list = list->next;
		}
		list = sorted_node;
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

int main()
{
	t_stack	*top;
	t_stack	*top2;
	top = 0;
	append(&top, 3);
	append(&top, 2);
	append(&top, -4);
	append(&top, 1);
	append(&top2, 6);
	append(&top2, 5);
	append(&top2, 4);
	sorting(&top);
	while (top != 0)
	{
		printf("%d\n", top->data);
		top = top->next;
	}
}
