/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:15:41 by seongjch          #+#    #+#             */
/*   Updated: 2022/07/13 09:16:02 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void overlap(int data, t_stack *top)
{
	t_stack	*list;

	list = top;
	while (list != 0)
	{
		if (list->data == data)
		{
			write(1, "Error\n", 7);
			exit(0);
		}
		list = list->next;
	}
}
