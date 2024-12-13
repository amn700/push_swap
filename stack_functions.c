/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:32:17 by mohchaib          #+#    #+#             */
/*   Updated: 2024/12/13 02:10:22 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//function to create a stack node
t_stack	*stk_new(int nbr)
{
	t_stack	*new;

	new = ft_calloc(sizeof(t_stack), 1);
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->next = new;
	new->prev = new;
	return (new);
}

//functions to add a node to a stack
int	stk_add_front(t_stack *node, t_stack **stack, int *elements)
{
	t_stack	*previous;
	t_stack	*temp;
	int		i;

	if (!node)
		return (0);
	if (!(*stack))
	{
		*stack = node;
		*elements += 1;
		return (1);
	}
	if (!(*stack)->next)
	{
		(*stack)->next = node;
		(*stack)->prev = node;
		node->prev = *stack;
		node->next = *stack;
		(*stack)->index = 1;
		*elements += 1;
		return (1);
	}
	temp = *stack;
	previous = (*stack)->prev;
	previous->next = node;
	node->prev = previous;
	node->next = (*stack);
	(*stack)->prev = node;
	*elements += 1;
	i = 0;
	while (i < *elements)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
	return (1);
}

//functions to swap/reverse stack nodes
void	stk_swap(t_stack *a, t_stack *b)
{
	int tmp;
	tmp = a->nbr;
	a->nbr = b->nbr;
	b->nbr = tmp;

}

void	stk_rotate(t_stack **stack)
{
	int		last_index;
	t_stack	*tmp;
	int		i;

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

//function to delete a node from a stack
void	stk_delfirst(t_stack **stack, int *stack_elem)
{
	(*stack)->prev = (*stack)->next;
	*stack = (*stack)->next;
	*stack_elem -= 1;
}

//print the stack
void	print_stack(t_stack *stack)
{
	int	last;

	last = stack->prev->index;
	while (stack->index < last)
	{
		ft_printf("%i :%i\n", stack->index, stack->nbr);
		stack = stack->next;
	}
	ft_printf("%i :%i\n", stack->index, stack->nbr);
}

//create a stack out of argv
int	populate_stack(char **matrix, t_stack **stack, int *stack_elem)
{
	int				i;
	t_validnumber	number;

	i = 0;
	while (matrix[i])
	{
		number = ft_custom_atoi(matrix[i]);
		if (!number.valid || !stk_add_front(stk_new((int)number.number), stack,
				stack_elem))
			return (0);
		i++;
	}
	return (1);
}

//find duplicated argvs
int	check_duplicates(t_stack *stack, int stack_elem)
{
	t_stack	*tmp;
	int		i;
	int		j;

	tmp = stack;
	i = 0;
	stack = stack->next;
	while (i < stack_elem - 1)
	{
		j = 0;
		while (j < stack_elem - 1)
		{
			if (tmp->nbr == stack->nbr)
				return (0);
			stack = stack->next;
			j++;
		}
		tmp = tmp->next;
		stack = tmp->next;
		i++;
	}
	return (1);
}

//free the stack
void	free_stack(t_stack **stack, int stack_elem)
{
	t_stack	*tmp;

	tmp = *stack;
	while (stack_elem > 0)
	{
		tmp = tmp->next;
		free(*stack);
		*stack = tmp;
		stack_elem--;
	}
}

//check if the stack is sorted
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
