#include "push_swap.h"
#define testing 1

#if testing

void free_matrix(char **matrix)
{
	int i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

int main (int argc, char **argv)
{
	//handle no argvs
	if (argc < 2)
		return (1);
	t_stack *stack = NULL;
	int stack_elem = 0;
	// handle multiple argvs
	char *string = ft_holy_joint(argv, argc);
	if (!string)
		return (1);
	char **matrix = ft_split((const char *)string, ' ');
	if (!matrix)
		return (1);
	free(string);
	if (!check_input(matrix))
	{
		ft_printf("Error\n");
		return (free_matrix(matrix), 1);
	}
	if (!populate_stack(matrix, stack, argc, &stack_elem))
		return (1);
	// if(!check_duplicates(stack, stack_elem))
	// 	return (free_stack(&stack, stack_elem), 1);
	// if(!check_sorted(stack, stack_elem))
	// 	sort_list(&stack, stack_elem);
	// print_stack(stack);
	// free_stack(&stack, stack_elem);
	// return (0);
}


#else

int	ft_atoi(const char *nptr)
{
	int					sign;
	unsigned long long	total;

	sign = 1;
	total = 0;
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
		total = total * 10 + (*nptr - '0');
		if (total > 9223372036854775807 && sign == 1)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		nptr++;
	}
	return (total * sign);
}

t_stack *stk_new(int nbr)
{
    t_stack *new;
    new = ft_calloc (sizeof(t_stack), 1);
    if (!new)
        return NULL;
    new->nbr = nbr;
    return new;
}

int stk_add_front(t_stack *node, t_stack **stack, int *elements)
{
    t_stack *previous;
    t_stack *temp;
    if (!node)
        return 0;
    if (!(*stack))
    {
        *stack = node;
        *elements += 1;
        // ft_printf("first node\n");
        // ft_printf("elements: %i\n", *elements);
        return 1;
    }
    if (!(*stack)->next)
    {
        (*stack)->next = node;
        (*stack)->prev = node;
        node->prev = *stack;
        node->next = *stack;
        node->index = 1;
        *elements += 1;
        // ft_printf("second node\n");
        // ft_printf("elements: %i\n", *elements);
        return 1;
    }
    temp = *stack;
    previous = (*stack)->prev;
    previous->next = node;

    node->prev = previous;
    node->next = (*stack);
    (*stack)->prev = node;
    // ft_printf("extra node\n");
    *elements += 1;
    int i = 0;
    while (i < *elements)
    {
        temp->index = i;
        temp = temp->next;
        i++;
    }
    // ft_printf("elements: %i\n", *elements);
    return 1;
}

int populate_stack(char **matrix, t_stack **stack, int count, int *stack_elem)
{
	int i = 1;
	while (i < count)
	{
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

int main ()
{

	t_stack *node1 = stk_new(1);
	t_stack *node2 = stk_new(2);
	t_stack *node3 = stk_new(0);
	t_stack *node4 = stk_new(8);
	t_stack *node5 = stk_new(5);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node1;


	node1->prev = node5;
	node2->prev = node1;
	node3->prev = node2;
	node4->prev = node3;
	node5->prev = node4;

	node1->index = 0;
	node2->index = 1;
	node3->index = 2;
	node4->index = 3;
	node5->index = 4;


}

#endif