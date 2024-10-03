/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 02:24:01 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/10/03 02:05:58 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char *argv[]);
void	ft_free_args(char **args);
void	ft_free_stack(t_stack **stack);
void	ft_free_stack_and_args(t_stack **stack, char **args);
int		ft_check_ascending_order(t_stack *stack);

int	main(int argc, char *argv[])
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	char			**split_args;
	unsigned int	max_index;

	stack_a = NULL;
	stack_b = NULL;
	split_args = ft_initialize_args(argc, argv);
	max_index = ft_process_stack(split_args, &stack_a);
	if (!ft_check_ascending_order(stack_a))
	{
		ft_free_stack(&stack_a);
		return (1);
	}
	ft_sorting_stack(&stack_a, &stack_b, max_index, 0);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}

void	ft_free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
	return ;
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free((*stack)->num);
		free(*stack);
		*stack = temp;
	}
}

void	ft_free_stack_and_args(t_stack **stack, char **args)
{
	ft_free_stack(stack);
	ft_free_args(args);
}

int	ft_check_ascending_order(t_stack *stack)
{
	t_stack	*start;
	t_stack	*next;
	int		num1;
	int		num2;

	if (!stack)
		return (-1);
	start = stack;
	next = stack->next;
	while (next)
	{
		num1 = ft_atoi(start->num);
		num2 = ft_atoi(next->num);
		if (num1 > num2)
			return (1);
		start = next;
		next = next->next;
	}
	return (0);
}
