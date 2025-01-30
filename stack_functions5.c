/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 07:24:55 by mohchaib          #+#    #+#             */
/*   Updated: 2025/01/28 07:24:56 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*min;
	int		i;
	int		last_index;

	i = 0;
	min = stack->next;
	last_index = stack->prev->index;
	while (i <= last_index)
	{
		if (stack->nbr < min->nbr)
			min = stack;
		stack = stack->next;
		i++;
	}
	return (min);
}

t_stack	*find_largest(t_stack *stack)
{
	t_stack	*max;
	int		i;
	int		last_index;

	i = 0;
	max = stack->next;
	last_index = stack->prev->index;
	while (i <= last_index)
	{
		if (stack->nbr > max->nbr)
			max = stack;
		stack = stack->next;
		i++;
	}
	return (max);
}
