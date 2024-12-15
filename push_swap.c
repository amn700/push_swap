/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:32:14 by mohchaib          #+#    #+#             */
/*   Updated: 2024/12/13 09:50:26 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define testing 0

#if !testing

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
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
	ft_printf("%i\n", stack_elem);
	ft_printf("%i\n", check_sorted(stack_a, stack_elem));
	if (!check_sorted(stack_a, stack_elem))
		sort_list(&stack_a, &stack_b, stack_elem);
	print_stack(stack_a);
	free_stack(&stack_a, stack_elem);
	return (0);
}

#else

int main()
{
	t_stack *stack_a;
	// t_stack *stack_b;
	int stack_a_elem;
	// int stack_b_elem;
	
	stack_a_elem = 0;
	// stack_b_elem = 0;
	char *matrix[] = {"55", "33", "22"/*, "11", "44"*/, NULL};
	if (!populate_stack(matrix, &stack_a, &stack_a_elem))
	{
		free_stack(&stack_a, stack_a_elem);
		free_matrix(matrix);
		return (ft_printf("Error\n"), 1);
	}
	print_stack(stack_a);
	
	// ft_printf("smallest number: %i\n", find_smallest(stack_a));
	// ft_printf("largest number: %i\n", find_largest(stack_a));
	// ft_printf("position of 11: %i\n", find_position(stack_a, 11));

	// ft_printf("required moves : %i\n", calculate_move_cost(0, stack_elem).cost);
	// ft_printf("required moves : %i\n", calculate_move_cost(1, stack_elem).cost);
	// ft_printf("required moves : %i\n", calculate_move_cost(2, stack_elem).cost);
	// ft_printf("required moves : %i\n", calculate_move_cost(3, stack_elem).cost);
	// ft_printf("required moves : %i\n", calculate_move_cost(4, stack_elem).cost);
	sort_three(&stack_a);
	print_stack(stack_a);

	free_stack(&stack_a, stack_a_elem);
}

#endif