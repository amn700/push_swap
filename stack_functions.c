#include "push_swap.h"

//function to create a stack node
t_stack *stk_new(int nbr)
{
    t_stack *new;
    new = ft_calloc (sizeof(t_stack), 1);
    if (!new)
        return NULL;
    new->nbr = nbr;
    return new;
}

//functions to add a node to a stack
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

//functions to swap/reverse stack nodes
void stk_swap(t_stack *a, t_stack *b)
{
    t_stack tmp;

    tmp.nbr = a->nbr;
    tmp.index = a->index;
    tmp.next = a->next;
    tmp.prev = a->prev;

    a->nbr = b->nbr;
    a->index = b->index;
    a->next = b->next;
    a->prev = b->prev;

    b->nbr = tmp.nbr;
    b->index = tmp.index;
    b->next = tmp.next;
    b->prev = tmp.prev;
}

void stk_rotate(t_stack **stack)
{
    t_stack *tmp = (*stack)->next;
    int i = 0;
    while (tmp->index)
    {
        tmp->index = i++;
        tmp = tmp->next;
    }
    tmp->index = i;
    *stack = (*stack)->next;
}

void stk_rev_rotate(t_stack **stack)
{
    int last_index = (*stack)->prev->index;
    t_stack *tmp = (*stack)->prev;
    int i = 0;
    while (i < last_index)
    {
        tmp->index = i++;
        tmp = tmp->next;
    }
    tmp->index = i;
    *stack = (*stack)->prev;
}

//function to delete a node from a stack
void stk_delfirst(t_stack **stack, int *stack_elem)
{
    (*stack)->prev = (*stack)->next;
    *stack = (*stack)->next;
    *stack_elem -= 1;
}
