/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 04:14:33 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/10/02 04:24:55 by tcosta-f         ###   ########.fr       */
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
	printf("rra\n");
	return ;
}

void	rrb(t_stack ***stack)
{
	ft_reverse_rotate(&stack);
	printf("rrb\n");
	return ;
}

void	rrr(t_stack ***stack_a, t_stack ***stack_b)
{
	ft_reverse_rotate(&stack_a);
	ft_reverse_rotate(&stack_b);
	printf("rrr\n");
	return ;
}
