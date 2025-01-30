/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:32:14 by mohchaib          #+#    #+#             */
/*   Updated: 2025/01/28 07:12:20 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		stack_elem;
	char	**matrix;

	if (argc < 2)
		return (1);
	stack_elem = 0;
	matrix = param_parser(argv, argc);
	if (!matrix)
		return (ft_printf("Error\n"), 1);
	if (!populate_stack(matrix, &stack_a, &stack_elem))
	{
		free_stack(&stack_a, stack_elem);
		return (free_matrix(matrix), ft_printf("Error\n"), 1);
	}
	free_matrix(matrix);
	fix_index(&stack_a, &stack_elem);
	if (!check_duplicates(stack_a, stack_elem))
		return (free_stack(&stack_a, stack_elem), ft_printf("Error\n"), 1);
	if (!check_sorted(stack_a, stack_elem))
		sort_list(&stack_a, &stack_elem);
	free_stack(&stack_a, stack_elem);
	return (0);
}
