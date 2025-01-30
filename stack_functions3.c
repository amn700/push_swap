/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 06:08:39 by mohchaib          #+#    #+#             */
/*   Updated: 2025/01/27 04:15:06 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	median_cmp(t_stack *stack, int elem)
{
	int	i;
	int	median;

	i = 0;
	median = elem / 2;
	if (!elem)
		return ;
	while (i < elem)
	{
		if (stack->index <= median)
			stack->calcule->abv_median = 1;
		else
			stack->calcule->abv_median = 0;
		stack = stack->next;
		i++;
	}
}

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	a_cost_func(t_stack *a, int a_elem)
{
	int	a_cost;

	if (a->calcule->abv_median)
		a_cost = a->index;
	else
		a_cost = a_elem - a->index;
	return (a_cost);
}

static int	b_cost_func(t_stack *a, int b_elem)
{
	int	b_cost;

	if (a->calcule->target->calcule->abv_median)
		b_cost = a->calcule->target->index;
	else
		b_cost = b_elem - a->calcule->target->index;
	return (b_cost);
}

void	cost_calcule_a(t_stack *a, int a_elem, int b_elem)
{
	int	i;
	int	a_cost;
	int	b_cost;

	i = 0;
	while (i < a_elem)
	{
		a_cost = a_cost_func(a, a_elem);
		b_cost = b_cost_func(a, b_elem);
		if (a->calcule->abv_median && a->calcule->target->calcule->abv_median)
			a->calcule->cost = max(a_cost, b_cost);
		if (!a->calcule->abv_median && !a->calcule->target->calcule->abv_median)
			a->calcule->cost = max(a_cost, b_cost);
		else
			a->calcule->cost = a_cost + b_cost;
		a = a->next;
		i++;
	}
}
