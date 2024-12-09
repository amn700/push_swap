#include "push_swap.h"
#define testing 1

#if testing

int main (int argc, char **argv)
{
	t_stack *stack = NULL;
	int stack_elem = 0;
	int i = 1;
	while (i < argc)
	{
		if (!check_input(argv[i]));
			free_stack(&stack);
		stack = stk_add_front(stk_new(ft_atoi(argv[i])), &stack, &stack_elem);
		i++;
	}
	if(!check_duplicates(stack))
	{
		free_stack(&stack);
		return (0);
	}
	if(!check_sorted(stack))
	{
		free_stack(&stack);
		return (0);
	}
	return (0);
}

#else

int	main ()
{
	ft_printf("Hello, World!\n");
}

#endif