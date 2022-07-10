/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:39:54 by seongjch          #+#    #+#             */
/*   Updated: 2022/07/10 21:55:21 by seongjch         ###   ########.fr       */
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
void	sorting(t_stack **top);
void 	copy(t_stack **dest, t_stack **src);
int		find_middle(t_stack	**top);
int		find_min(t_stack **top);

#endif
