#include "push_swap.h"
//////////*parsing*//////////

//custom atoi function
t_validnumber ft_custom_atoi(const char *nptr)
{
	int				sign;
	t_validnumber	total;

	sign = 1;
	total.number = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		total.number = total.number * 10 + (*nptr - '0');
		//-2147483648 && 2147483647
		if (total.number > 2147483648)
			return (total.valid = 0, total);
		nptr++;
	}
	total.number *= sign;
	if (total.number == 2147483648)
		return (total.valid = 0, total);
	return (total.valid = 1, total);
}

//check for valid input
int check_input(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '-' || str[i][j] == '+')
			j++;
		while (str[i][j])
		{
			if(!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//create a stack out of argv
int populate_stack(char **matrix, t_stack **stack, int *stack_elem)
{
	int i = 0;
	t_validnumber number;
   	while (matrix[i])
	{
		number = ft_custom_atoi(matrix[i]);
		if (!number.valid || !stk_add_front(stk_new((int)number.number), stack, stack_elem))
			return 0;
		i++;
	}
	return (1);
}

//find duplicated argvs
int check_duplicates(t_stack *stack, int stack_elem)
{
	t_stack *tmp = stack;
	int i = 0;
	int j;
	stack = stack->next;
	while (i < stack_elem - 1)
	{
		j = 0;
		while (j < stack_elem -1)
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
void free_stack(t_stack **stack, int stack_elem)
{
	t_stack *tmp = *stack;
	while (stack_elem > 0)
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
	t_stack *tmp = stack;
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

void free_matrix(char **matrix)
{
	int i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}
