/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:29:35 by seongjch          #+#    #+#             */
/*   Updated: 2022/07/13 07:55:58 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	swap(t_stack	*top)
{
	int	temp;

	temp = top->data;
	top->data = top->next->data;
	top->next->data = temp;
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
	t_stack *list;

	list = *top;
	if (list == 0 || list->next == 0)
		return ;
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

void copy(t_stack **dest, t_stack **src, int n)
{
	t_stack *list;
	t_stack *src_list;

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
			printf("sa\n");
			swap(*a_top);
			//print_all(*a_top, *b_top);
		}
		return ;
	}
	mid = find_mid(*a_top, to_push);
	while (to_push)
	{
		if ((*a_top)->data > mid)
		{
			printf("ra\n");
			rotate(a_top);
			//print_all(*a_top, *b_top);
			rotate_cnt++;
		}
		else
		{
			printf("pb\n");
			push(b_top, a_top);
			//print_all(*a_top, *b_top);
			pushed++;
		}
		to_push--;
	}
	while (rotate_cnt > cnt)
	{
		printf("rra\n");
		reverse_rotate(a_top);
		//print_all(*a_top, *b_top);
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
		printf("pa\n");
		push(a_top, b_top);
		//print_all(*a_top, *b_top);
		return ;
	}
	mid = find_mid(*b_top, pushed);
	while (pushed)
	{
		if ((*b_top)->data < mid)
		{
			printf("rb\n");
			rotate(b_top);
			//print_all(*a_top, *b_top);
			rotate_cnt++;
		}
		else
		{
			printf("pa\n");
			push(a_top, b_top);
			//print_all(*a_top, *b_top);
			to_push++;
		}
		pushed--;
	}
	while (rotate_cnt > cnt)
	{
		printf("rrb\n");
		reverse_rotate(b_top);
		//print_all(*a_top, *b_top);
		cnt++;
	}
	a_to_b(a_top, b_top, to_push);
	b_to_a(a_top, b_top, rotate_cnt);
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

void print_all(t_stack *a, t_stack *b)
{
	printf("a\n");
	while (a != 0)
	{
		printf("| %d |\n", a->data);
		a = a->next;
	}
	printf("----------------\n");
	printf("b\n");
	while (b != 0)
	{
		printf("| %d |\n", b->data);
		b = b->next;
	}
	printf("----------------\n");
}
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
void sort_5(t_stack **a, t_stack **b)
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
			continue;
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

void sort_3(t_stack **a)
{
	int	val;
	int	checker;
	t_stack *list;

	list = *a;
	checker = 0;
	val = list->data;
	list = list->next;
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
	else if (checker == 0)
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

int main(int argc,	char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		val;
	int		i;

	if (argc < 2)
		return (0);
	a = 0;
	b = 0;
	i = argc - 1;
	while (i > 0)
	{
		val = ft_atoi(argv[i]);
		overlap(val, a);
		append(&a, val);
		i--;
	}
	if (is_sort(a,len_stack(a)))
		return (0);
	if (len_stack(a) == 3)
		sort_3(&a);
	else if (len_stack(a) == 5)
		sort_5(&a, &b);
	else
		a_to_b(&a,&b, argc - 1);
	//print_all(a, b);
}
