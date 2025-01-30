/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 07:24:43 by mohchaib          #+#    #+#             */
/*   Updated: 2025/01/28 07:24:43 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stk_swap(t_stack *a, t_stack *b)
{
	int	tmp;

	if (!a || !b)
		return ;
	tmp = a->nbr;
	a->nbr = b->nbr;
	b->nbr = tmp;
}

void	stk_rotate(t_stack **stack)
{
	int		last_index;
	t_stack	*tmp;
	int		i;

	if (!(*stack) || !stack)
		return ;
	last_index = (*stack)->prev->index;
	*stack = (*stack)->next;
	tmp = *stack;
	i = 0;
	while (i <= last_index)
	{
		tmp->index = i++;
		tmp = tmp->next;
	}
}

void	stk_rev_rotate(t_stack **stack)
{
	int		last_index;
	t_stack	*tmp;
	int		i;

	if (!(*stack) || !stack)
		return ;
	last_index = (*stack)->prev->index;
	tmp = (*stack)->prev;
	i = 0;
	while (i < last_index)
	{
		tmp->index = i++;
		tmp = tmp->next;
	}
	tmp->index = i;
	*stack = (*stack)->prev;
}

void	stk_delfirst(t_stack **stack, int *stack_elem)
{
	t_stack	*tmp;

	tmp = *stack;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	*stack = tmp->next;
	*stack_elem -= 1;
}

void	print_stack(t_stack *stack, int stack_elem)
{
	int	i;

	i = 0;
	while (i < stack_elem)
	{
		ft_printf("%i :%i\n", stack->index, stack->nbr);
		stack = stack->next;
		i++;
	}
}
