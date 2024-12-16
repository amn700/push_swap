/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:32:17 by mohchaib          #+#    #+#             */
/*   Updated: 2024/12/16 15:46:59 by mohchaib         ###   ########.fr       */
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

void fix_index(t_stack **stack, int *elements)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (i < *elements)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

void first_node(t_stack *node, t_stack **stack, int *elements)
{
	*stack = node;
	*elements += 1;
}

void second_node(t_stack *node, t_stack **stack, int *elements)
{
	(*stack)->prev = node;
	(*stack)->next = node;
	node->prev = *stack;
	node->next = *stack;
	node->index = 1;
	*elements += 1;
}

void another_node(t_stack *node, t_stack **stack, int *elements)
{
	(*stack)->prev->next = node;
	node->prev = (*stack)->prev;
	node->next = (*stack);
	(*stack)->prev = node;
	*elements += 1;
}

//functions to add a node to a stack
int		stk_add_front(t_stack *node, t_stack **stack, int *elements)
{	
	if (!node)
		return (0);
	if (*elements == 0)
		return (first_node(node, stack, elements), 1);                                     
	if (*elements == 1)
		return (second_node(node, stack, elements), 1);
	another_node(node, stack, elements);
	
	return (fix_index(stack, elements), 1);
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

//function to REMOVE the first node of a stack WITHOUT FREEING IT
void	stk_delfirst(t_stack **stack, int *stack_elem)
{
	t_stack	*tmp;

	tmp = *stack;

	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	*stack = tmp->next;
	*stack_elem -= 1;
}

//print the stack
void	print_stack(t_stack *stack, int stack_elem)
{
	int i = 0;

	while (i < stack_elem)
	{
		ft_printf("%i :%i\n", stack->index, stack->nbr);
		stack = stack->next;
		i++;
	}
}

//create a stack out of argv
int		populate_stack(char **matrix, t_stack **stack, int *stack_elem)
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
int		check_duplicates(t_stack *stack, int stack_elem)
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
