/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:32:14 by mohchaib          #+#    #+#             */
/*   Updated: 2024/12/13 02:10:45 by mohchaib         ###   ########.fr       */
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
	if(!matrix)
		return (ft_printf("Error\n"), 1);
	if (!populate_stack(matrix, &stack_a, &stack_elem))
	{
		
		free_stack(&stack_a, stack_elem);
		free_matrix(matrix);
		return (ft_printf("Error\n"), 1);
	}
	free_matrix(matrix);

	if (!check_duplicates(stack_a, stack_elem))
		return (ft_printf("Error\n"), 1);

	if (!check_sorted(stack_a, stack_elem))
		sort_list(&stack_a, stack_elem);
	// ft_printf("index :%i number: %i\n", stack_a->index, stack_a->nbr);
	// stack_a = stack_a->next;
	// ft_printf("index :%i number: %i\n", stack_a->index, stack_a->nbr);
	// stack_a = stack_a->next;
	// ft_printf("index :%i number: %i\n", stack_a->index, stack_a->nbr);
	print_stack(stack_a);
	// free_stack(&stack_a, stack_elem);
	return (0);
}
