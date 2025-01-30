/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:11:43 by mohchaib          #+#    #+#             */
/*   Updated: 2025/01/30 00:13:51 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	empty_arg_check(char **argv, int argc)
{
	int	i;
	int	j;
	int	only_spaces;

	i = 1;
	while (i < argc)
	{
		only_spaces = 1;
		j = 0;
		while (argv[i][j])
		{
			if (!ft_is_space(argv[i][j]))
				only_spaces = 0;
			j++;
		}
		if (only_spaces || j == 0)
			return (0);
		i++;
	}
	return (1);
}
