/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 08:49:35 by seongjch          #+#    #+#             */
/*   Updated: 2022/07/13 13:01:45 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_a(t_stack **a, char **argv[], int i)
{
	int		j;
	char	**splited;
	int		val;

	while (i > 0)
	{
		splited = ft_split((*argv)[i], ' ');
		j = 0;
		while (splited[j] != 0)
			j++;
		while (--j >= 0)
		{
			val = ft_atoi(splited[j]);
			overlap(val, *a);
			append(a, val);
		}
		while (splited[++j] != 0)
			free(splited[j]);
		free(splited);
		i--;
	}
}

int	main(int argc,	char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = 0;
	b = 0;
	init_a(&a, &argv, argc - 1);
	if (is_sort(a, len_stack(a)))
		return (0);
	if (len_stack(a) == 3)
		sort_3(&a);
	else if (len_stack(a) == 5)
		sort_5(&a, &b);
	else
		a_to_b(&a, &b, len_stack(a));
}
