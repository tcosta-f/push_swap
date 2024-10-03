/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 02:43:13 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/10/03 02:13:20 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int		ft_process_stack(char **split_args, t_stack **stack_a);
static int			ft_check_args_reps(char **args);
static unsigned int	ft_indexing(t_stack **stack, int min,
						unsigned int *index, int max_index);
static int			ft_find_lower_number(t_stack **stack, int min);
static long			ft_atol(const char *nptr);

unsigned int	ft_process_stack(char **split_args, t_stack **stack_a)
{
	unsigned int	i;
	unsigned int	max_index;

	i = 0;
	max_index = ft_check_args_reps(split_args);
	ft_fill_stack(split_args, stack_a);
	ft_indexing(stack_a, INT_MIN, &i, max_index);
	return (max_index);
}

static int	ft_check_args_reps(char **args)
{
	int	i;
	int	j;

	j = 0;
	while (args[j])
	{
		i = j + 1;
		while (args[i])
		{
			if (!ft_strcmp(args[j], args[i]))
			{
				write(2, "Error\n", 6);
				ft_free_args(args);
				exit(1);
			}
			i++;
		}
		j++;
	}
	return (j);
}

static unsigned int	ft_indexing(t_stack **stack, int min,
						unsigned int *index, int max_index)
{
	int		lower;
	int		current_num;
	t_stack	*current;

	lower = INT_MAX;
	current = *stack;
	if (max_index == 0 || !*stack)
		return (*index);
	lower = ft_find_lower_number(stack, min);
	current = *stack;
	while (current)
	{
		current_num = ft_atoi(current->num);
		if (current_num == lower)
		{
			current->index = *index;
			break ;
		}
		current = current->next;
	}
	(*index)++;
	min = lower;
	return (ft_indexing(stack, min, index, max_index - 1));
}

static int	ft_find_lower_number(t_stack **stack, int min)
{
	int		lower;
	long	current_num;
	t_stack	*current;

	lower = INT_MAX;
	current = *stack;
	while (current)
	{
		current_num = ft_atol(current->num);
		if (current_num < INT_MIN || current_num > INT_MAX)
		{
			write(2, "Error\n", 6);
			ft_free_stack(stack);
			exit(1);
		}
		else if ((current_num > min) && (current_num < lower))
			lower = current_num;
		current = current->next;
	}
	return (lower);
}

static long	ft_atol(const char *nptr)
{
	long	i;
	int		sign;
	char	*temp;

	i = 0;
	sign = 1;
	temp = (char *)nptr;
	while (*temp == ' ' || (*temp >= '\t' && *temp <= '\r'))
		temp++;
	if (*temp == '-' || *temp == '+')
	{
		if (*temp == '-')
			sign *= -1;
		temp++;
	}
	if (ft_strncmp((char *)temp, "9223372036854775808", 20) == 0 && sign == -1)
		return (-9223372036854775807L - 1);
	while (*temp >= '0' && *temp <= '9')
	{
		i = i * 10 + (*temp - '0');
		temp++;
	}
	return (i * sign);
}
