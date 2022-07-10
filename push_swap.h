/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:39:54 by seongjch          #+#    #+#             */
/*   Updated: 2022/07/10 15:46:44 by seongjch         ###   ########.fr       */
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

#endif
