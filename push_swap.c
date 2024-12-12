#include "push_swap.h"
#define testing 1

#if testing

int main (int argc, char **argv)
{
	//handle no argvs
	if (argc < 2)
		return (1);
	t_stack *stack_a;
	int stack_elem = 0;
////////////////////////////////////////////////////////////////////////
	// handle multiple argvs
	char *string = ft_holy_joint(argv, argc);
	if (!string)
		return (1);
	//handle mixed numbers 
	char **matrix = ft_split((const char *)string, ' ');
	if (!matrix)
		return (1);
	free(string);
	//handle invalid input
	if (!check_input(matrix))
		return (ft_printf("Error\n"), free_matrix(matrix), 1);
////////////////////////////////////////////////////////////////////////
	//populate the stack
	if (!populate_stack(matrix, &stack_a, &stack_elem))
	{
		ft_printf("Error\n");
		free_stack(&stack_a, stack_elem);
		free_matrix(matrix);
		return (1);
	}
	free_matrix(matrix);

	// check for duplicates
	if(!check_duplicates(stack_a, stack_elem))
	{
		ft_printf("Error\n");
		return (1);
	}
	
	//check if the stack is already sorted
	if(!check_sorted(stack_a, stack_elem))
	{
		ft_printf("Not sorted\n");
		// sort_list(&stack_a, stack_elem);
		return (1);
	}
	ft_printf("Already sorted\n");

	print_stack(stack_a);
	free_stack(&stack_a, stack_elem);
	return (0);
}


#else

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