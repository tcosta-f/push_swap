/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-f <tcosta-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 02:34:30 by tcosta-f          #+#    #+#             */
/*   Updated: 2024/10/03 02:12:09 by tcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char		**ft_initialize_args(int argc, char *argv[]);
static char	*ft_handle_args(int argc, char **argv);
static char	*ft_join_arguments(char *args, int argc, char **argv);
static char	*ft_add_space_if_needed(char *args, int argc, int i);
static int	ft_check_args(char *args);

char	**ft_initialize_args(int argc, char *argv[])
{
	char	*args;
	char	**split_args;

	if (argc < 2)
		exit(1);
	args = ft_handle_args(argc, argv);
	if (!args)
		exit(1);
	if (ft_check_args(args))
		exit(1);
	split_args = ft_split(args, ' ');
	free(args);
	if (!split_args)
		exit(1);
	return (split_args);
}

static char	*ft_handle_args(int argc, char **argv)
{
	char	*args;

	if (argc < 2 || !argv[1])
		exit(1);
	args = ft_strdup("");
	if (!args)
		exit(1);
	args = ft_join_arguments(args, argc, argv);
	return (args);
}

static char	*ft_join_arguments(char *args, int argc, char **argv)
{
	char	*temp;
	int		i;

	i = 1;
	while (i < argc)
	{
		temp = ft_strjoin(args, argv[i]);
		if (!temp)
		{
			free(args);
			exit(1);
		}
		free(args);
		args = temp;
		args = ft_add_space_if_needed(args, argc, i);
		i++;
	}
	return (args);
}

static char	*ft_add_space_if_needed(char *args, int argc, int i)
{
	char	*temp;

	if (i + 1 < argc)
	{
		temp = ft_strjoin(args, " ");
		if (!temp)
		{
			free(args);
			exit(1);
		}
		free(args);
		args = temp;
	}
	return (args);
}

static int	ft_check_args(char *args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (args[i] == '-' && args[i + 1] >= '0' && args[i + 1] <= '9')
			i++;
		else if ((args[i] < '0' || args[i] > '9') && args[i] != ' ')
		{
			write(2, "Error\n", 6);
			free(args);
			return (1);
		}
		i++;
	}
	return (0);
}
