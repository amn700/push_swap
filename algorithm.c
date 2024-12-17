/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:32:02 by mohchaib          #+#    #+#             */
/*   Updated: 2024/12/17 11:47:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sorts the stack
void	sort_two(t_stack **stack)
{
	if ((*stack)->nbr > (*stack)->next->nbr)
		swap_a(*stack);
}

void	sort_three(t_stack **stack)
{
	if ((*stack)->nbr < (*stack)->next->nbr && (*stack)->nbr < (*stack)->next->next->nbr)
	{
		swap_a(*stack);
		rotate_a(stack);
	}
	if ((*stack)->nbr > (*stack)->next->nbr && (*stack)->nbr > (*stack)->next->next->nbr)
		rotate_a(stack);
	if ((*stack)->nbr > (*stack)->next->nbr && (*stack)->nbr < (*stack)->next->next->nbr)
		swap_a(*stack);
	if ((*stack)->nbr < (*stack)->next->nbr && (*stack)->nbr > (*stack)->next->next->nbr)
		r_rotate_a(stack);
}

void	sort_five(t_stack **stack_a,t_stack **stack_b, int *stack_elem, int *b_elem)
{
	// ft_printf("A STACK starting point\n");
	// print_stack(*stack_a, *stack_elem);
	// ft_printf("B STACK\n");
	// print_stack(*stack_b, *b_elem);
	// ft_printf("------------------------------\n");
	// //max 11 moves
	push_b(stack_a, stack_b, stack_elem, b_elem);
	// ft_printf("A STACK\n");
	// print_stack(*stack_a, *stack_elem);
	// ft_printf("B STACK\n");
	// print_stack(*stack_b, *b_elem);
	// ft_printf("------------------------------\n");
	push_b(stack_a, stack_b, stack_elem, b_elem);
	// ft_printf("A STACK\n");
	// print_stack(*stack_a, *stack_elem);
	// ft_printf("B STACK\n");
	// print_stack(*stack_b, *b_elem);
	// ft_printf("------------------------------\n");
	sort_three(stack_a);//max 2 moves
	ft_printf("A STACK\n");
	print_stack(*stack_a, *stack_elem);
	ft_printf("B STACK\n");
	print_stack(*stack_b, *b_elem);
	ft_printf("------------------------------\n");
	// // // figure out how to put the neeewly added element in the right place
	// // //use math to determine what moves are needed
	rotate_to_top(stack_a, find_optimal_position(*stack_a, (*stack_b)->nbr), rotate_a, r_rotate_a);
	ft_printf("A STACK\n");
	print_stack(*stack_a, *stack_elem);
	ft_printf("B STACK\n");
	print_stack(*stack_b, *b_elem);
	ft_printf("------------------------------\n");
	push_a(stack_a, stack_b, stack_elem, b_elem);
	ft_printf("A STACK\n");
	print_stack(*stack_a, *stack_elem);
	ft_printf("B STACK\n");
	print_stack(*stack_b, *b_elem);
	ft_printf("------------------------------\n");
	rotate_to_top(stack_a, find_optimal_position(*stack_a, (*stack_b)->nbr), rotate_a, r_rotate_a);
	push_a(stack_a, stack_b, stack_elem, b_elem);
	ft_printf("A STACK\n");
	print_stack(*stack_a, *stack_elem);
	ft_printf("B STACK\n");
	print_stack(*stack_b, *b_elem);
	ft_printf("------------------------------\n");
	// figure out how to put the other element in the right place
	return ;
}


void    sort_list(t_stack **stack_a, int *stack_elem)
{
	t_stack *stack_b = NULL;
	int b_elem;

	b_elem = 0;
	if (*stack_elem == 2)
		return (sort_two(stack_a));
	if (*stack_elem == 3)
		return (sort_three(stack_a));
	if (*stack_elem == 5)
		return (sort_five(stack_a, &stack_b, stack_elem, &b_elem));
	// print_stack(stack_b, b_elem);
	// 	while stack_a is not empty:
	// choose a pivot value
	// for each element in stack_a:
	//     if element < pivot:
	//         pb (push to b)
	//     else:
	//         ra (rotate a)
	// while stack_b is not empty:
    // find the largest element in stack_b
    // move it to the top of stack_b using rb or rrb
    // pa (push it to stack_a)
	// while stack_a is not sorted:
    // if the largest element is at the bottom:
    //     rra (reverse rotate)
    // else:
    //     ra (rotate)
	// for each element in stack_a:
    // calculate cost to move it to stack_b
    // calculate cost to position it correctly in stack_b
    // choose the element with the least cost
	// while (!is_empty(stack_a)) {
	//     pivot = choose_pivot(stack_a);
	//     for (each element in stack_a) {
	//         if (element < pivot)
	//             push_b(stack_a, stack_b);
	//         else
	//             rotate_a(stack_a);
	//     }
	// }
	// while (!is_empty(stack_b)) {
	//     largest = find_largest(stack_b);
	//     rotate_to_top(stack_b, largest);
	//     push_a(stack_b, stack_a);
	// }
	// rotate_a_to_sort(stack_a);


	// if (stack_elem == 100)
	// 	return (sort_a_hundred(stack_a, stack_b, stack_elem));
	// if (stack_elem == 500)
	// 	return (sort_five_hundred(stack_a, stack_b, stack_elem));
}

// void	sort_a_hundred(t_stack **stack,t_stack **stack_b, int stack_elem)
// {
// 	return ;
// }

// void	sort_five_hundred(t_stack **stack,t_stack **stack_b, int stack_elem)
// {
// 	return ;
// }