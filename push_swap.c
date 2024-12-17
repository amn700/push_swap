/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:32:14 by mohchaib          #+#    #+#             */
/*   Updated: 2024/12/17 12:32:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define testing 0
#if testing 

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
	fix_index(&stack_a, &stack_elem);
	if (!check_duplicates(stack_a, stack_elem))
		return (ft_printf("Error\n"), 1);
	if (!check_sorted(stack_a, stack_elem))
		sort_list(&stack_a, &stack_elem);
	// ft_printf("A STACK\n");
	// print_stack(stack_a, stack_elem);
	// free_stack(&stack_a, stack_elem);
	return (0);
}


#else

int main (int argc, char **argv)
{
	(void)argc;
	t_stack *stack_a;
	int a_elem;
	t_stack *stack_b;
	int b_elem;
	
	if (!populate_stack(argv+1, &stack_a, &a_elem))
	{
		free_stack(&stack_a, a_elem);
		return (ft_printf("Error\n"), 1);
	}
	fix_index(&stack_a, &a_elem);
	ft_printf("A STACK\n");
	print_stack(stack_a, a_elem);
	ft_printf("B STACK\n");
	print_stack(stack_b, b_elem);
	ft_printf("------------------------------\n");
	push_b(&stack_a, &stack_b, &a_elem, &b_elem);
	push_b(&stack_a, &stack_b, &a_elem, &b_elem);
	if (!check_sorted(stack_a, a_elem))
		sort_three(&stack_a);
	ft_printf("A STACK\n");
	print_stack(stack_a, a_elem);
	ft_printf("B STACK\n");
	print_stack(stack_b, b_elem);
	ft_printf("------------------------------\n");
	rotate_to_top(&stack_a, find_optimal_position(stack_a, (stack_b)->nbr), rotate_a, r_rotate_a);
	ft_printf("A STACK\n");
	print_stack(stack_a, a_elem);
	ft_printf("B STACK\n");
	print_stack(stack_b, b_elem);
	ft_printf("------------------------------\n");
	push_a(&stack_a, &stack_b, &a_elem, &b_elem);
	ft_printf("A STACK\n");
	print_stack(stack_a, a_elem);
	ft_printf("B STACK\n");
	print_stack(stack_b, b_elem);
	ft_printf("------------------------------\n");
	rotate_to_top(&stack_a, find_optimal_position(stack_a, (stack_b)->nbr), rotate_a, r_rotate_a);
	// push_a(&stack_a, &stack_b, &a_elem, &b_elem);
	// ft_printf("A STACK\n");
	// print_stack(stack_a, a_elem);
	// ft_printf("B STACK\n");
	// print_stack(stack_b, b_elem);
	// ft_printf("------------------------------\n");
}

#endif