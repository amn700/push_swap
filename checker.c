/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 07:23:31 by mohchaib          #+#    #+#             */
/*   Updated: 2025/01/28 07:23:31 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_this_shit(t_stack **stack_a,
	int *stack_elem)
{
	t_stack	*stack_b;
	int		b_elem;

	stack_b = NULL;
	b_elem = 0;
	if (!check_sorted(*stack_a, *stack_elem))
	{
		if (!run_operations(stack_a, stack_elem, &stack_b, &b_elem))
			return ((void)ft_printf("Error\n"));
	}
	if (!check_sorted(*stack_a, *stack_elem) || b_elem)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		stack_elem;
	char	**matrix;

	if (argc < 2)
		return (0);
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
	{
		free_stack(&stack_a, stack_elem);
		return (ft_printf("Error\n"), 1);
	}
	init_this_shit(&stack_a, &stack_elem);
	return (free_stack(&stack_a, stack_elem), (0));
}
