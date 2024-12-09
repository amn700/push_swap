/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 06:53:26 by marvin            #+#    #+#             */
/*   Updated: 2024/12/09 07:25:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//////////*excution*//////////

//(sa , sb)     swap first node with second
void	swap_a(t_stack *stack)
{
	stk_swap(stack, stack->next);
	ft_printf("sa\n");
}

void	swap_b(t_stack *stack)
{
	stk_swap(stack, stack->next);
	ft_printf("sb\n");
}

//(ss) swap first nodes of 2 stacks
void	swap_ss(t_stack *stacka, t_stack *stackb)
{
	stk_swap(stacka, stacka->next);
	stk_swap(stackb, stackb->next);
	ft_printf("ss\n");
}

//(pa,pb) take a node from the top of a stack and put it ontop of the other stack
void	push_a(t_stack **stacka, t_stack **stackb, int *stack_elem)
{
	if (!stk_add_front(*stacka, stackb, stack_elem))
		return ;
	stk_delfirst(stacka, stack_elem);
	ft_printf("pa\n");
}

void	push_b(t_stack **stacka, t_stack **stackb, int *stack_elem)
{
	if (!stk_add_front(*stackb, stacka, stack_elem))
		return ;
	stk_delfirst(stackb, stack_elem);
	ft_printf("pb\n");
}

//(ra, rb) put the first node in the end of the stack
void	rotate_a(t_stack **stacka)
{
	stk_rotate(stacka);
	ft_printf("ra\n");
}

void	rotate_b(t_stack **stackb)
{
	stk_rotate(stackb);
	ft_printf("rb\n");
}

//(rr) put the first nodeint the end of the stack for noth stacks
void	rotate_rr(t_stack **stackb, t_stack **stacka)
{
	stk_rotate(stacka);
	stk_rotate(stackb);
	ft_printf("rr\n");
}

//(rra, rrb) put the last node in the start of the stack
void	r_rotate_a(t_stack **stacka)
{
	stk_rev_rotate(stacka);
	ft_printf("rra\n");
}

void	r_rotate_b(t_stack **stackb)
{
	stk_rev_rotate(stackb);
	ft_printf("rrb\n");
}

//(rrr)  put the last node in the start of the stack for both stacks
void	r_rotate_rr(t_stack **stacka, t_stack **stackb)
{
	stk_rev_rotate(stacka);
	stk_rev_rotate(stackb);
	ft_printf("rrr\n");
}
