/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 07:24:25 by mohchaib          #+#    #+#             */
/*   Updated: 2025/01/28 07:24:33 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stk_new(int nbr)
{
	t_stack	*new;

	new = ft_calloc(sizeof(t_stack), 1);
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->next = new;
	new->prev = new;
	new->calcule = ft_calloc(sizeof(t_cost), 1);
	new->calcule->abv_median = 0;
	new->calcule->cheapest = 0;
	new->calcule->cost = 0;
	new->calcule->target = NULL;
	return (new);
}

static void	first_node(t_stack *node, t_stack **stack, int *elements)
{
	*stack = node;
	(*stack)->prev = node;
	(*stack)->next = node;
	*elements += 1;
}

static void	second_node(t_stack *node, t_stack **stack, int *elements)
{
	(*stack)->prev = node;
	(*stack)->next = node;
	node->prev = *stack;
	node->next = *stack;
	*elements += 1;
}

static void	another_node(t_stack *node, t_stack **stack, int *elements)
{
	(*stack)->prev->next = node;
	node->prev = (*stack)->prev;
	node->next = (*stack);
	(*stack)->prev = node;
	*elements += 1;
}

int	stk_add_front(t_stack *node, t_stack **stack, int *elements)
{
	if (!node)
		return (0);
	if (*elements == 0)
		return (first_node(node, stack, elements), 1);
	if (*elements == 1)
		return (second_node(node, stack, elements), 1);
	another_node(node, stack, elements);
	return (1);
}
