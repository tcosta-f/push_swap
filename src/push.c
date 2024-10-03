/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 04:13:24 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/10/03 18:23:05 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack ****stack_src, t_stack ****stack_dest);
void		pa(t_stack ***stack_b, t_stack ***stack_a);
void		pb(t_stack ***stack_a, t_stack ***stack_b);

static void	ft_push(t_stack ****stack_src, t_stack ****stack_dest)
{
	t_stack	*temp;

	if (!(**stack_src) || !(***stack_src))
		return ;
	temp = ***stack_src;
	***stack_src = (***stack_src)->next;
	temp->next = ***stack_dest;
	***stack_dest = temp;
}

void	pa(t_stack ***stack_b, t_stack ***stack_a)
{
	ft_push(&stack_b, &stack_a);
	write(1, "pa\n", 3);
	return ;
}

void	pb(t_stack ***stack_a, t_stack ***stack_b)
{
	ft_push(&stack_a, &stack_b);
	write(1, "pb\n", 3);
	return ;
}
