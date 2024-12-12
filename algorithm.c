#include "push_swap.h"

//sorts the stack

//print the stack
void print_stack(t_stack *stack)
{
    int last = stack->prev->index;
    while (stack->index < last)
    {
        ft_printf("%i :%i\n",stack->index, stack->nbr);
        stack = stack->next;
    }
    ft_printf("%i :%i\n",stack->index, stack->nbr);
}
