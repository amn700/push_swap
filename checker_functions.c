/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:44:51 by marvin            #+#    #+#             */
/*   Updated: 2025/01/30 23:04:20 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s2)
	{
		if ((unsigned char )*s1 == (unsigned char )*s2)
		{
			s1++;
			s2++;
		}
		else
			return (1);
	}
	return (0);
}

int	swaps(char *line, t_stack*stack_a, t_stack*stack_b, int **tab)
{
	if (!ft_strcmp(line, "sa\n"))
	{
		if (*tab[0] >= 2)
			return (free(line), swap_a(stack_a, 0), (1));
		return (free(line), (1));
	}
	else if (!ft_strcmp(line, "sb\n"))
	{
		if (*tab[1] >= 2)
			return (free(line), swap_a(stack_b, 0), (1));
		return (free(line), (1));
	}
	else if (!ft_strcmp(line, "ss\n"))
	{
		if (*tab[0] >= 2)
			swap_a(stack_a, 0);
		if (*tab[1] >= 2)
			swap_b(stack_a, 0);
		return (free(line), (1));
	}
	return (0);
}

int	rotations(char *line, t_stack**stack_a, t_stack**stack_b)
{
	if (!ft_strcmp(line, "ra\n"))
		return (free(line), rotate_a(stack_a, 0), (1));
	else if (!ft_strcmp(line, "rb\n"))
		return (free(line), rotate_b(stack_b, 0), (1));
	else if (!ft_strcmp(line, "rr\n"))
		return (free(line), rotate_rr(stack_a, stack_b, 0), (1));
	else if (!ft_strcmp(line, "rra\n"))
		return (free(line), r_rotate_a(stack_a, 0), (1));
	else if (!ft_strcmp(line, "rrb\n"))
		return (free(line), r_rotate_b(stack_b, 0), (1));
	else if (!ft_strcmp(line, "rrr\n"))
		return (free(line), r_rotate_rr(stack_a, stack_b, 0), (1));
	return (0);
}

int	run_operations(t_stack **stack_a, int *a_elem,
	t_stack **stack_b, int *b_elem)
{
	char	*line;
	int		*tab[2];

	tab[0] = a_elem;
	tab[1] = b_elem;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (swaps(line, *stack_a, *stack_b, tab))
			continue ;
		else if (rotations(line, stack_a, stack_b))
			continue ;
		else if (!ft_strcmp(line, "pa\n"))
			push_a_bonus(stack_a, stack_b, a_elem, b_elem);
		else if (!ft_strcmp(line, "pb\n"))
			push_b_bonus(stack_a, stack_b, a_elem, b_elem);
		else
			return (free(line), (0));
	}
	return (free(line), (1));
}
