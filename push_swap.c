#include "push_swap.h"
#define testing 1

#if testing
int main (int argc, char **argv)
{
	//handle multiple argvs and no argvs
	if (argc < 2)
		return (1);
	// t_stack *stack = NULL;
	// int stack_elem = 0;

	//he who must not be named
	char *string = ft_holy_joint(argv, argc);
	if (!string)
		return (1);
	ft_printf("the full string : %s\n", string);
	char **matrix = ft_split((const char *)string, ' ');
	if (!matrix)
		return (1);
	
	// ft_printf("%i\n", sizeof(matrix)/ sizeof(char *));
	// if (!populate_stack(matrix, stack, argc, &stack_elem))
	// 	return (1);
	// if(!check_duplicates(stack, stack_elem))
	// 	return (free_stack(&stack, stack_elem), 1);
	// if(!check_sorted(stack, stack_elem))
	// 	sort_list(&stack, stack_elem);
	// print_stack(stack);
	// free_stack(&stack, stack_elem);
	// return (0);
}


#else
int main (int argc, char **argv)
{
	(void)argc;
	char **matrix = ft_split((const char *)argv[1], ' ');
	for(int i = 0; matrix[i]; i++)
		ft_printf("%s\n", matrix[i]);
	// t_stack *node1 = stk_new(1);
	// t_stack *node2 = stk_new(2);
	// t_stack *node3 = stk_new(0);
	// t_stack *node4 = stk_new(8);
	// t_stack *node5 = stk_new(5);

	// node1->next = node2;
	// node2->next = node3;
	// node3->next = node4;
	// node4->next = node5;
	// node5->next = node1;


	// node1->prev = node5;
	// node2->prev = node1;
	// node3->prev = node2;
	// node4->prev = node3;
	// node5->prev = node4;

	// node1->index = 0;
	// node2->index = 1;
	// node3->index = 2;
	// node4->index = 3;
	// node5->index = 4;

}

#endif