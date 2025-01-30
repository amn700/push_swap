/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:14:45 by mohchaib          #+#    #+#             */
/*   Updated: 2025/01/28 08:19:58 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **stacka, int print)
{
	stk_rotate(stacka);
	if (print)
		ft_printf("ra\n");
}

void	rotate_b(t_stack **stackb, int print)
{
	stk_rotate(stackb);
	if (print)
		ft_printf("rb\n");
}

void	rotate_rr(t_stack **stackb, t_stack **stacka, int print)
{
	stk_rotate(stacka);
	stk_rotate(stackb);
	if (print)
		ft_printf("rr\n");
}
