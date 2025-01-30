/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 07:25:05 by mohchaib          #+#    #+#             */
/*   Updated: 2025/01/30 00:52:24 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack, int print)
{
	stk_swap(stack, stack->next);
	if (print)
		ft_printf("sa\n");
}

void	swap_b(t_stack *stack, int print)
{
	stk_swap(stack, stack->next);
	if (print)
		ft_printf("sb\n");
}

void	swap_ss(t_stack *stacka, t_stack *stackb, int print)
{
	stk_swap(stacka, stacka->next);
	stk_swap(stackb, stackb->next);
	if (print)
		ft_printf("ss\n");
}
