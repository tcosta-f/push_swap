/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 04:14:04 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/10/02 04:26:43 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack ****stack);
void		sa(t_stack ***stack);
void		sb(t_stack ***stack);
void		ss(t_stack ***stack_a, t_stack ***stack_b);

static void	ft_swap(t_stack ****stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*stack) || !(**stack) || !(***stack)->next)
		return ;
	first = ***stack;
	second = (***stack)->next;
	first->next = second->next;
	second->next = first;
	***stack = second;
}

void	sa(t_stack ***stack)
{
	ft_swap(&stack);
	printf("sa\n");
	return ;
}

void	sb(t_stack ***stack)
{
	ft_swap(&stack);
	printf("sb\n");
	return ;
}

void	ss(t_stack ***stack_a, t_stack ***stack_b)
{
	ft_swap(&stack_a);
	ft_swap(&stack_b);
	printf("ss\n");
	return ;
}
