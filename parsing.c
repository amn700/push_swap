#include "push_swap.h"
//////////*parsing*//////////

//check for valid input
int check_input(char* str)
{
	int i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if(!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

//create a stack out of argv
int populate_stack(char **matrix, t_stack **stack, int count, int *stack_elem)
{
	int i = 1;
   	while (i < count)
	{
		if (!check_input(matrix[i]))
		{
			ft_printf("Error\n");
			// return (free_stack(&stack, i), 0);
			return 0;
		}
		if (!stk_add_front(stk_new(ft_atoi(matrix[i])), stack, stack_elem))
		{
			ft_printf("Error\n");
			// return (free_stack(&stack, i), 0);
			return 0;
		}
		i++;
	}
	return (1);
}

//find duplicated argvs
int check_duplicates(t_stack *stack, int stack_elem)
{
	t_stack	*tmp;
	while (stack->index < stack_elem - 1)
	{
		tmp = stack->next;
		while (tmp->index < stack_elem - 1)
		{
			if (stack->nbr == tmp->nbr)
				return (0);
			tmp = tmp->next;
		}
		stack = stack->next;
		// stack = tmp->next;
	}
	return (1);
}

//free the stack
void free_stack(t_stack **stack, int stack_elem)
{
	t_stack *tmp = *stack;
	while (stack_elem != -1)
	{
		tmp = tmp->next;
		free(*stack);
		*stack = tmp;
		stack_elem--;
	}
}

//check if the stack is sorted
int check_sorted(t_stack* stack, int stack_elem)
{
	t_stack	*tmp = stack->next;
	int min;
	while (tmp->index < stack_elem - 1)
	{
		min = tmp->nbr;
		while (stack->index < stack_elem - 1)
		{
			if (stack->nbr < min)
				return (0);
			stack = stack->next;
		}
		tmp = tmp->next;
		stack = tmp->next;
	}
	return (1);
}
