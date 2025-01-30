/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 06:53:26 by marvin            #+#    #+#             */
/*   Updated: 2025/01/26 03:20:56 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **stacka, t_stack **stackb, int *a_elem, int *b_elem)
{
	t_stack	*tmp;

	if (*b_elem == 0)
		return ;
	tmp = *stackb;
	stk_delfirst(stackb, b_elem);
	fix_index(stackb, b_elem);
	stk_add_front(tmp, stacka, a_elem);
	*stacka = tmp;
	fix_index(stacka, a_elem);
	ft_printf("pa\n");
}

void	push_b(t_stack **stacka, t_stack **stackb, int *a_elem, int *b_elem)
{
	t_stack	*tmp;

	if (*a_elem == 0)
		return ;
	tmp = *stacka;
	stk_delfirst(stacka, a_elem);
	fix_index(stacka, a_elem);
	stk_add_front(tmp, stackb, b_elem);
	*stackb = tmp;
	fix_index(stackb, b_elem);
	ft_printf("pb\n");
}
