/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:36:00 by mohchaib          #+#    #+#             */
/*   Updated: 2024/12/12 19:48:34 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_validnumber ft_custom_atoi(const char *nptr)
{
	int				sign;
	t_validnumber	total;

	sign = 1;
	total.number = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		total.number = total.number * 10 + (*nptr - '0');
		//-2147483648 && 2147483647
		if (total.number > 2147483648)
			return (total.valid = 0, total);
		nptr++;
	}
	total.number *= sign;
	if (total.number == 2147483648)
		return (total.valid = 0, total);
	return (total.valid = 1, total);
}

//dont touch it !!
char *ft_holy_joint(char **argv, int argc)
{
	int i = 1;
	char * temp;
	char * str = ft_strdup("");
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

int check_input(char **str)
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
			if(!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char    **param_parser(char **argv, int argc)
{
    char    *string;
    char    **matrix;

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

//free the matrix
void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}
