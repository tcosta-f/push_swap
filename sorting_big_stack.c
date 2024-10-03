/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 00:30:12 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/10/03 00:38:44 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_sorting_big_stack(t_stack **stack_a, t_stack **stack_b,
						unsigned int max_index, unsigned int bit);
static unsigned int	ft_count_significant_bits(unsigned int max_index);

void	ft_sorting_big_stack(t_stack **stack_a, t_stack **stack_b,
				unsigned int max_index, unsigned int bit)
{
	int				bit_value;
	unsigned int	i;
	unsigned int	max_bit;

	max_bit = ft_count_significant_bits(max_index);
	while (bit <= max_bit)
	{
		i = 0;
		while (i < max_index)
		{
			bit_value = ((*stack_a)->index >> bit) & 1;
			if (bit_value == 0)
				pb(&stack_a, &stack_b);
			else
				ra(&stack_a);
			i++;
		}
		while (*stack_b)
			pa(&stack_b, &stack_a);
		if (!ft_check_ascending_order(*stack_a))
			return ;
		bit++;
	}
	return ;
}

static unsigned int	ft_count_significant_bits(unsigned int max_index)
{
	unsigned int	count;

	count = 0;
	while (max_index > 0)
	{
		max_index >>= 1;
		count++;
	}
	return (count);
}
