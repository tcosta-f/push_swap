/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 04:12:56 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/10/03 03:36:57 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_sorting_stack(t_stack **stack_a, t_stack **stack_b,
						unsigned int max_index, unsigned int bit);
static void			ft_sorting_small_stack(t_stack **stack_a, t_stack **stack_b,
						unsigned int max_index);
static void			ft_move_lowest_to_stack_b(t_stack **stack_a,
						t_stack **stack_b, unsigned int *max_index);
static void			ft_rotate_stack(t_stack **stack_a, t_stack *temp, size_t i,
						unsigned int *max_index);
static void			ft_sort_three(t_stack **stack_a);

void	ft_sorting_stack(t_stack **stack_a, t_stack **stack_b,
						unsigned int max_index, unsigned int bit)
{
	if (max_index <= 5)
		ft_sorting_small_stack(stack_a, stack_b, max_index);
	else
		ft_sorting_big_stack(stack_a, stack_b, max_index, bit);
	return ;
}

static void	ft_sort_three(t_stack **stack_a)
{
	while (ft_check_ascending_order(*stack_a))
	{
		if ((*stack_a)->index < (*stack_a)->next->index
			&& (*stack_a)->next->index > (*stack_a)->next->next->index)
			rra(&stack_a);
		else if (((*stack_a)->index > (*stack_a)->next->index
				&& (*stack_a)->next->index < (*stack_a)->next->next->index
				&& (*stack_a)->index > (*stack_a)->next->next->index)
			|| ((*stack_a)->index > (*stack_a)->next->index
				&& (*stack_a)->next->index > (*stack_a)->next->next->index))
			ra(&stack_a);
		else if ((*stack_a)->index > (*stack_a)->next->index
			&& (*stack_a)->next->index < (*stack_a)->next->next->index
			&& (*stack_a)->index < (*stack_a)->next->next->index)
			sa(&stack_a);
	}
}

static void	ft_sorting_small_stack(t_stack **stack_a, t_stack **stack_b,
				unsigned int max_index)
{
	if (max_index == 2)
		return (ra(&stack_a));
	else if (max_index == 3)
		ft_sort_three(stack_a);
	else if (max_index == 4 || max_index == 5)
	{
		ft_move_lowest_to_stack_b(stack_a, stack_b, &max_index);
		return (ft_sorting_small_stack(stack_a, stack_b, max_index));
	}
	while (*stack_b)
		pa(&stack_b, &stack_a);
}

static void	ft_rotate_stack(t_stack **stack_a, t_stack *temp, size_t i,
						unsigned int *max_index)
{
	while (temp->index != (*stack_a)->index)
	{
		if (i <= (*max_index) / 2)
			ra(&stack_a);
		else
			rra(&stack_a);
	}
}

static void	ft_move_lowest_to_stack_b(t_stack **stack_a, t_stack **stack_b,
						unsigned int *max_index)
{
	t_stack	*head;
	size_t	i;
	size_t	lower_num;

	head = *stack_a;
	i = 0;
	lower_num = 0;
	while (*max_index > 3)
	{
		if (head->index == lower_num)
		{
			ft_rotate_stack(stack_a, head, i, max_index);
			pb(&stack_a, &stack_b);
			lower_num++;
			head = *stack_a;
			(*max_index)--;
			i = 0;
		}
		else
		{
			head = head->next;
			i++;
		}
	}
}
