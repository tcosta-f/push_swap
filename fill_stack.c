/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 02:53:45 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/10/03 02:11:40 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_fill_stack(char **args, t_stack **stack_a);
static int		ft_add_element_to_stack(char *arg, t_stack **stack_a);
static t_stack	*ft_create_node(void);
static int		ft_validate_num(const char *num_str);
static void		ft_add_node_to_stack(t_stack **stack, t_stack *new_node);

void	ft_fill_stack(char **args, t_stack **stack_a)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_add_element_to_stack(args[i], stack_a) == 1)
		{
			ft_free_stack_and_args(stack_a, args);
			exit(1);
		}
		i++;
	}
	ft_free_args(args);
	return ;
}

static int	ft_add_element_to_stack(char *arg, t_stack **stack_a)
{
	t_stack	*new_node;

	new_node = ft_create_node();
	if (!new_node)
		return (1);
	new_node->num = ft_strdup(arg);
	if (!new_node->num)
	{
		free(new_node);
		return (1);
	}
	if (ft_validate_num(new_node->num))
	{
		free(new_node->num);
		free(new_node);
		return (1);
	}
	ft_add_node_to_stack(stack_a, new_node);
	return (0);
}

static t_stack	*ft_create_node(void)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->num = NULL;
	new_node->next = NULL;
	new_node->index = -1;
	return (new_node);
}

static int	ft_validate_num(const char *num_str)
{
	long int	num_value;

	num_value = (long int)ft_atoi(num_str);
	if (num_value < INT_MIN || num_value > INT_MAX)
		return (1);
	return (0);
}

static void	ft_add_node_to_stack(t_stack **stack, t_stack *new_node)
{
	t_stack	*current;

	if (*stack == NULL)
		*stack = new_node;
	else
	{
		current = *stack;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}
