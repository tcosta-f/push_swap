/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:05:48 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/09/05 18:17:07 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"

typedef	struct s_stack
{
	char *num;
	char *index;
	t_stack *next;	
}		t_stack;



int	main(int argc, char *argv[])
{
	
}

void	ft_find_min(t_stack *stack, int min, int argc)
{
    t_stack 		*lower;
    t_stack 		*current;
	unsigned int	index;

    if (!stack)
        return ;
	if (argc == 0)
		return ;
    lower = stack;
    current = stack->next;
    while (current)
    {
		if (ft_atoi(current->num) < ft_atoi(lower->num) && ft_atoi(current->num) > min)
            lower = current;
        current = current->next;
    }
	lower->index = ft_itoa(index);
	min = ft_atoi(lower->num);
	if (!stack)
		ft_find_min(stack, min, argc--);
    return ;
}

#include <limits.h>  // Para usar INT_MIN

void	ft_find_min(t_stack *stack, int min, int *index, int argc)
{
    t_stack *lower = NULL;
    t_stack *current = stack;

    // Condições de parada
    if (argc == 0 || !stack)
        return;

    // Procurar o menor valor maior que "min"
    while (current)
    {
        if ((ft_atoi(current->num) > min) && (!lower || ft_atoi(current->num) < ft_atoi(lower->num)))
            lower = current;
        current = current->next;
    }

    // Atribuir o índice ao menor valor encontrado
    if (lower)
    {
        lower->index = *index;  // Atribuir o índice como um número inteiro
        (*index)++;  // Incrementar o índice
        min = ft_atoi(lower->num);  // Atualizar "min" para o menor valor encontrado
    }

    // Chamar a função recursivamente para encontrar o próximo menor valor
    ft_find_min(stack, min, index, argc - 1);
}

