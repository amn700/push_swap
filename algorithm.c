/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:32:02 by mohchaib          #+#    #+#             */
/*   Updated: 2025/01/28 07:23:23 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*biggest;

	biggest = find_largest(*stack);
	if (biggest->nbr == (*stack)->nbr)
		rotate_a(stack, 1);
	else if ((*stack)->next->nbr == biggest->nbr)
		r_rotate_a(stack, 1);
	if ((*stack)->nbr > (*stack)->next->nbr)
		swap_a(*stack, 1);
}

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b,
	int *a_elem, int *b_elem)
{
	t_stack	*cheapest_node;
	int		tab[2];

	tab[0] = *a_elem;
	tab[1] = *b_elem;
	cheapest_node = thats_the_cheapest(*stack_a, *a_elem);
	if (cheapest_node->calcule->abv_median
		&& cheapest_node->calcule->target->calcule->abv_median)
		rotate_both(stack_a, stack_b, cheapest_node, tab);
	else if (!cheapest_node->calcule->abv_median
		&& !cheapest_node->calcule->target->calcule->abv_median)
		rev_rotate_both(stack_a, stack_b, cheapest_node, tab);
	move_node_to_top(stack_a, cheapest_node, 'a');
	move_node_to_top(stack_b, cheapest_node->calcule->target, 'b');
	push_b(stack_a, stack_b, a_elem, b_elem);
}

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b,
		int *a_elem, int *b_elem)
{
	move_node_to_top(stack_a, (*stack_b)->calcule->target, 'a');
	push_a(stack_a, stack_b, a_elem, b_elem);
}

void	fix_sorted_stack(t_stack **stack_a)
{
	while ((*stack_a)->nbr != find_smallest(*stack_a)->nbr)
	{
		if (find_smallest(*stack_a)->calcule->abv_median)
			rotate_a(stack_a, 1);
		else
			r_rotate_a(stack_a, 1);
	}
}

void	sort_list(t_stack **stack_a, int *a_elem)
{
	t_stack	*stack_b;
	int		b_elem;

	stack_b = NULL;
	b_elem = 0;
	if (*a_elem == 2)
		return (swap_a(*stack_a, 1));
	if (*a_elem > 3 && !check_sorted(*stack_a, *a_elem))
		push_b(stack_a, &stack_b, a_elem, &b_elem);
	if (*a_elem > 3 && !check_sorted(*stack_a, *a_elem))
		push_b(stack_a, &stack_b, a_elem, &b_elem);
	while (*a_elem > 3 && !check_sorted(*stack_a, *a_elem))
	{
		initialize_nodes_a(*stack_a, stack_b, *a_elem, b_elem);
		move_a_to_b(stack_a, &stack_b, a_elem, &b_elem);
	}
	sort_three(stack_a);
	while (b_elem)
	{
		initialize_nodes_b(*stack_a, stack_b, *a_elem, b_elem);
		move_b_to_a(stack_a, &stack_b, a_elem, &b_elem);
	}
	median_cmp(*stack_a, *a_elem);
	fix_sorted_stack(stack_a);
}
