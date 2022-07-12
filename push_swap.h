/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:39:54 by seongjch          #+#    #+#             */
/*   Updated: 2022/07/13 03:20:07 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define	PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack{
	struct s_stack	*next;
	int				data;
}	t_stack;

void	append(t_stack **top, int new_data);
void	push(t_stack	**dest, t_stack	**src);
void	swap(t_stack	**top);
void	rotate(t_stack **top);
void	reverse_rotate(t_stack **top);
void	sorting(t_stack *top);
void 	copy(t_stack **dest, t_stack **src, int n);
int		find_mid(t_stack	*top, int n);
int		find_min(t_stack *top);
int		is_sort(t_stack *top, int len);
int		is_revers_sort(t_stack *top);
void	a_to_b(t_stack **a_top, t_stack **b_top, int to_push);
void	b_to_a(t_stack **a_top, t_stack **b_top, int pushed);
int		is_min(t_stack *top, int min);
int		ft_atoi(const char	*str);
void	overlap(int data, t_stack *top);
void	print_all(t_stack *a, t_stack *b);

#endif
