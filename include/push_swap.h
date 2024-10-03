/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 03:58:45 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/10/03 17:32:55 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	char			*num;
	size_t			index;
	struct s_stack	*next;
}	t_stack;

char			**ft_initialize_args(int argc, char *argv[]);
unsigned int	ft_process_stack(char **split_args, t_stack **stack_a);
void			ft_fill_stack(char **args, t_stack **stack_a);
int				ft_check_ascending_order(t_stack *stack);
void			ft_sorting_stack(t_stack **stack_a, t_stack **stack_b,
					unsigned int max_index, unsigned int bit);
void			ft_sorting_big_stack(t_stack **stack_a, t_stack **stack_b,
					unsigned int max_index, unsigned int bit);
void			ft_free_args(char **args);
void			ft_free_stack(t_stack **stack);
void			ft_free_stack_and_args(t_stack **stack, char **args);
void			pa(t_stack ***stack_b, t_stack ***stack_a);
void			pb(t_stack ***stack_a, t_stack ***stack_b);
void			sa(t_stack ***stack);
void			sb(t_stack ***stack);
void			ss(t_stack ***stack_a, t_stack ***stack_b);
void			ra(t_stack ***stack);
void			rb(t_stack ***stack);
void			rr(t_stack ***stack_a, t_stack ***stack_b);
void			rra(t_stack ***stack);
void			rrb(t_stack ***stack);
void			rrr(t_stack ***stack_a, t_stack ***stack_b);
#endif