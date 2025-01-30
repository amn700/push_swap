/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 07:24:50 by mohchaib          #+#    #+#             */
/*   Updated: 2025/01/28 07:24:50 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **stack_a, t_stack **stack_b,
	t_stack *cheapest_node, int *tab)
{
	while (*stack_a != cheapest_node
		&& *stack_b != cheapest_node->calcule->target)
		rotate_rr(stack_a, stack_b, 1);
	median_cmp(*stack_a, tab[0]);
	median_cmp(*stack_b, tab[1]);
}

void	rev_rotate_both(t_stack **stack_a, t_stack **stack_b,
	t_stack *cheapest_node, int *tab)
{
	while (*stack_a != cheapest_node
		&& *stack_b != cheapest_node->calcule->target)
		r_rotate_rr(stack_a, stack_b, 1);
	median_cmp(*stack_a, tab[0]);
	median_cmp(*stack_b, tab[1]);
}

void	initialize_nodes_a(t_stack *a, t_stack *b, int a_elem, int b_elem)
{
	median_cmp(a, a_elem);
	median_cmp(b, b_elem);
	choose_target_a(a, b, a_elem, b_elem);
	cost_calcule_a(a, a_elem, b_elem);
	whats_the_cheapest(a, a_elem);
}

void	initialize_nodes_b(t_stack *a, t_stack *b, int a_elem, int b_elem)
{
	median_cmp(a, a_elem);
	median_cmp(b, b_elem);
	choose_target_b(a, b, a_elem, b_elem);
}

void	move_node_to_top(t_stack **stack, t_stack *cheapest, char name)
{
	while (*stack != cheapest)
	{
		if (name == 'a')
		{
			if (cheapest->calcule->abv_median)
				rotate_a(stack, 1);
			else
				r_rotate_a(stack, 1);
		}
		else if (name == 'b')
		{
			if (cheapest->calcule->abv_median)
				rotate_b(stack, 1);
			else
				r_rotate_b(stack, 1);
		}
	}
}
