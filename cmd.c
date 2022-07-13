/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:29:35 by seongjch          #+#    #+#             */
/*   Updated: 2022/07/13 09:30:12 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack	*top)
{
	int	temp;

	temp = top->data;
	top->data = top->next->data;
	top->next->data = temp;
}

void	push(t_stack	**dest, t_stack	**src)
{
	t_stack	*for_free;

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
	t_stack	*list;
	int		temp;

	list = *top;
	temp = (*top)->data;
	if (list->next == 0)
		return ;
	while (list->next != 0)
	{
		list->data = list->next->data;
		list = list->next;
	}
	list->data = temp;
}

void	reverse_rotate(t_stack **top)
{
	t_stack	*list;

	list = *top;
	if (list == 0 || list->next == 0)
		return ;
	while (list -> next -> next != 0)
		list = list -> next;
	append(top, list->next->data);
	free(list -> next);
	list -> next = 0;
}
