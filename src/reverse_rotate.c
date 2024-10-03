/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 04:14:33 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/10/03 18:23:53 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_stack ****stack);
void		rra(t_stack ***stack);
void		rrb(t_stack ***stack);
void		rrr(t_stack ***stack_a, t_stack ***stack_b);

static void	ft_reverse_rotate(t_stack ****stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*pre_last;

	if (!(*stack) || !(**stack) || !(***stack)->next)
		return ;
	first = ***stack;
	pre_last = ***stack;
	while (pre_last->next->next)
		pre_last = pre_last->next;
	last = pre_last->next;
	last->next = first;
	***stack = last;
	pre_last->next = NULL;
	return ;
}

void	rra(t_stack ***stack)
{
	ft_reverse_rotate(&stack);
	write(1, "rra\n", 4);
	return ;
}

void	rrb(t_stack ***stack)
{
	ft_reverse_rotate(&stack);
	write(1, "rrb\n", 4);
	return ;
}

void	rrr(t_stack ***stack_a, t_stack ***stack_b)
{
	ft_reverse_rotate(&stack_a);
	ft_reverse_rotate(&stack_b);
	write(1, "rrr\n", 4);
	return ;
}
