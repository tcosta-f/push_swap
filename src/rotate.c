/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 04:14:21 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/10/02 04:25:55 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack ****stack);
void		ra(t_stack ***stack);
void		rb(t_stack ***stack);
void		rr(t_stack ***stack_a, t_stack ***stack_b);

static void	ft_rotate(t_stack ****stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!(**stack) || !(***stack) || !(***stack)->next)
		return ;
	first = ***stack;
	last = ***stack;
	while (last->next)
		last = last->next;
	last->next = first;
	***stack = first->next;
	first->next = NULL;
}

void	ra(t_stack ***stack)
{
	ft_rotate(&stack);
	printf("ra\n");
	return ;
}

void	rb(t_stack ***stack)
{
	ft_rotate(&stack);
	printf("rb\n");
	return ;
}

void	rr(t_stack ***stack_a, t_stack ***stack_b)
{
	ft_rotate(&stack_a);
	ft_rotate(&stack_b);
	printf("rr\n");
	return ;
}
