/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 06:08:39 by mohchaib          #+#    #+#             */
/*   Updated: 2024/12/17 12:27:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//find the smallest number in the stack
int		find_smallest(t_stack *stack)
{
	int min; 
	int i;
	int last_index;

	i = 0;
	min = stack->nbr;
	last_index = stack->prev->index;
	while (i <= last_index)
	{
		if (stack->nbr < min)
			min = stack->nbr;
		stack = stack->next;
		i++;
	}
	return (min);
}

//find the largest number in the stack
int		find_largest(t_stack *stack)
{
	int max;
	int i;
	int last_index;

	i = 0;
	max = stack->nbr;
	last_index = stack->prev->index;
	while (i <= last_index)
	{
		if (stack->nbr > max)
			max = stack->nbr;
		stack = stack->next;
		i++;
	}
	return (max);
}

//find optimal position for a number in the stack
int		find_optimal_position(t_stack *stack, int number)
{
	int i;
	int last_index;
	int min;
	int max;

	i = 0;
	min = find_smallest(stack);
	max = find_largest(stack);
	ft_printf("min = %i\n", min);
	ft_printf("max = %i\n", max);
	ft_printf("number = %i\n", number);
	last_index = stack->prev->index;
	// ft_printf("last index = %i\n", last_index);
	if (number < min)
		return (0);
	else if (number > max)
		return (last_index);
	while (i <= last_index)
	{
		ft_printf("stack->nbr = %i\nstack->next->nbr = %i\n", stack->nbr, stack->next->nbr);
		if (number > stack->nbr && number < stack->next->nbr) 
			return (ft_printf("%i\n", i+1) ,i + 1);
		stack = stack->next;
		i++;
	}
	return (-1);
}

//find the position of a number in the stack
int		find_position(t_stack *stack, int number)
{
	int i;
	int last_index;

	i = 0;
	last_index = stack->prev->index;
	while (i <= last_index)
	{
		if (stack->nbr == number)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

//check if the stack is sorted
int		check_sorted(t_stack *stack, int stack_elem)
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

//calculate the cost of moving a number to the top of the stack
t_cost	calculate_move_cost(int target_position, int stack_elem)
{
	int forward_cost = target_position;
	int reverse_cost = stack_elem - target_position;

	//keep in mind that u have to redo the same moves to return the stack into the right position
	if (forward_cost <= reverse_cost)
		return ((t_cost){forward_cost, 1});
	return ((t_cost){reverse_cost, 0});
}

//rotate the stack untill the element in the specific position is on top
void rotate_to_top(t_stack **stack, int target_position, void (*rotate)(t_stack **stack), void (*reverse_rotate)(t_stack **stack))
{
    t_cost cost = calculate_move_cost(target_position, (*stack)->prev->index);
	ft_printf("cost : %i",cost.cost);
	ft_printf("forward : %i",cost.forward);
    while (cost.cost--)
	{
        if (cost.forward)
            rotate(stack);
        else
            reverse_rotate(stack);
    }
}

// void	rotate_to_top(t_stack **stack, int position)
// {
// 	return ;
// }

// void	rotate_to_sorted(stack);
