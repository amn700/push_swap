/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 07:24:59 by mohchaib          #+#    #+#             */
/*   Updated: 2025/01/28 07:25:00 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	whats_the_cheapest(t_stack *stack, int elem)
{
	int		i;
	long	cheapest;
	t_stack	*point;

	i = 0;
	cheapest = LONG_MAX;
	while (i < elem)
	{
		if (stack->calcule->cost < cheapest)
		{
			cheapest = stack->calcule->cost;
			point = stack;
		}
		stack = stack->next;
		i++;
	}
	point->calcule->cheapest = 1;
}

t_stack	*thats_the_cheapest(t_stack *stack, int stack_elem)
{
	int	i;

	i = 0;
	while (i < stack_elem)
	{
		if (stack->calcule->cheapest)
			return (stack);
		stack = stack->next;
		i++;
	}
	return (NULL);
}

int	check_sorted(t_stack *stack, int stack_elem)
{
	t_stack	*tmp;

	tmp = stack;
	stack = stack->next;
	while (stack_elem > 1)
	{
		if (tmp->nbr > stack->nbr)
			return (0);
		tmp = tmp->next;
		stack = stack->next;
		stack_elem--;
	}
	return (1);
}
