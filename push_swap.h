#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

typedef struct s_stack
{
	int			nbr;
	int			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_operations
{
	char	*operation;
	void	(*f)(t_stack *stack);
}	t_operations;

typedef struct a_validnumber
{
	int		valid;
	long		number;
}t_validnumber;

//stack functions
t_stack	*stk_new(int nbr);
int	stk_add_front(t_stack *node, t_stack **stack, int *elements);
void	stk_swap(t_stack *a, t_stack *b);
void	stk_rotate(t_stack **stack);
void	stk_rev_rotate(t_stack **stack);
void	stk_delfirst(t_stack **stack, int *stack_elem);
//operations
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_ss(t_stack *stacka, t_stack *stackb);
void	push_a(t_stack **stacka, t_stack **stackb, int *stack_elem);
void	push_b(t_stack **stacka, t_stack **stackb, int *stack_elem);
void	rotate_a(t_stack **stacka);
void	rotate_b(t_stack **stackb);
void	rotate_rr(t_stack **stackb, t_stack **stacka);
void	r_rotate_a(t_stack **stacka);
void	r_rotate_b(t_stack **stackb);
void	r_rotate_rr(t_stack **stackb, t_stack **stacka);

void	print_stack(t_stack *stack);
void	free_stack(t_stack **stack, int stack_elem);
int check_sorted(t_stack* stack, int stack_elem);
int	check_duplicates(t_stack *stack, int stack_elem);
int	populate_stack(char **matrix, t_stack **stack, int *stack_elem);
int	check_input(char** str);
void free_matrix(char **matrix);

char *ft_holy_joint(char **argv, int argc);
#endif