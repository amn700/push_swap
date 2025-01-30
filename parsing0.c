/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 07:23:43 by mohchaib          #+#    #+#             */
/*   Updated: 2025/01/30 23:04:37 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**param_parser(char **argv, int argc)
{
	char	*string;
	char	**matrix;

	if (!empty_arg_check(argv, argc))
		return (NULL);
	string = ft_holy_joint(argv, argc);
	if (!string)
		return (NULL);
	matrix = ft_split((const char *)string, ' ');
	if (!matrix)
		return (NULL);
	free(string);
	if (!check_input(matrix))
		return (free_matrix(matrix), NULL);
	return (matrix);
}

char	*ft_holy_joint(char **argv, int argc)
{
	int		i;
	char	*temp;
	char	*str;

	i = 1;
	str = ft_strdup("");
	while (i < argc)
	{
		temp = ft_strjoin(str, argv[i++]);
		if (!temp)
			return (free(str), str = NULL, NULL);
		free(str);
		str = temp;
		temp = ft_strjoin(str, " ");
		if (!temp)
			return (free(str), str = NULL, NULL);
		free(str);
		str = temp;
	}
	return (str);
}

int	check_input(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '-' || str[i][j] == '+')
			j++;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}
