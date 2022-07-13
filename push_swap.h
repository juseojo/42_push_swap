/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:39:54 by seongjch          #+#    #+#             */
/*   Updated: 2022/07/13 11:29:16 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack{
	struct s_stack	*next;
	int				data;
}	t_stack;

typedef struct s_val{
	int	pushed;
	int	to_push;
	int	rotate_cnt;
}	t_val;

void	append(t_stack **top, int new_data);
void	push(t_stack	**dest, t_stack	**src);
void	swap(t_stack	*top);
void	rotate(t_stack **top);
void	reverse_rotate(t_stack **top);
void	sorting(t_stack *top);
void	copy(t_stack **dest, t_stack **src, int n);
int		find_mid(t_stack	*top, int n);
int		find_min(t_stack *top);
int		is_sort(t_stack *top, int len);
void	a_to_b(t_stack **a_top, t_stack **b_top, int to_push);
void	b_to_a(t_stack **a_top, t_stack **b_top, int pushed);
int		is_min(t_stack *top, int min);
int		ft_atoi(const char	*str);
void	overlap(int data, t_stack *top);
void	sort_3(t_stack **a);
void	sort_5(t_stack **a, t_stack **b);
char	**ft_split(char const *s, char c);
int		len_stack(t_stack	*top);
void	init_a(t_stack **a, char **argv[], int i);
void	free_and_next(t_stack **target);
void	free_son(t_stack **target);
#endif
