/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:13:25 by mohchaib          #+#    #+#             */
/*   Updated: 2025/01/26 03:15:07 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate_a(t_stack **stacka, int print)
{
	stk_rev_rotate(stacka);
	if (print)
		ft_printf("rra\n");
}

void	r_rotate_b(t_stack **stackb, int print)
{
	stk_rev_rotate(stackb);
	if (print)
		ft_printf("rrb\n");
}

void	r_rotate_rr(t_stack **stacka, t_stack **stackb, int print)
{
	stk_rev_rotate(stacka);
	stk_rev_rotate(stackb);
	if (print)
		ft_printf("rrr\n");
}
