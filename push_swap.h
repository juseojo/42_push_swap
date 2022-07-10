/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:39:54 by seongjch          #+#    #+#             */
/*   Updated: 2022/07/10 08:23:38 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define	PUSH_SWAP_H

typedef struct s_stack{
	struct s_stack	*next;
	int				data;
}	t_stack;

void	append(t_stack **top, int new_data);
void	push(t_stack	**dest, t_stack	**src);
void	swap(t_stack	**top);
void	rotate(t_stack **top);
void	reverse_rotate(t_stack **top);
int		cul_avg(t_stack *top);
int		abs(int val);
#endif
