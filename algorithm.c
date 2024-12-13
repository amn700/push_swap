/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:32:02 by mohchaib          #+#    #+#             */
/*   Updated: 2024/12/13 02:13:52 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sorts the stack
void    sort_list(t_stack **stack, int stack_elem)
{
   if (stack_elem == 2)
   {
       if ((*stack)->nbr > (*stack)->next->nbr)
           swap_a(*stack);
       return ;
   }
   if (stack_elem == 3)
   {
       if ((*stack)->nbr < (*stack)->next->nbr && (*stack)->nbr < (*stack)->next->next->nbr)
       {
           swap_a(*stack);
           rotate_a(stack);
       }
       if ((*stack)->nbr > (*stack)->next->nbr && (*stack)->nbr > (*stack)->next->next->nbr)
           rotate_a(stack);
       if ((*stack)->nbr > (*stack)->next->nbr && (*stack)->nbr < (*stack)->next->next->nbr)
           swap_a(*stack);
       if ((*stack)->nbr < (*stack)->next->nbr && (*stack)->nbr > (*stack)->next->next->nbr)
           r_rotate_a(stack);
       return ;
   }
}
