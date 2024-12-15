/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:32:20 by mohchaib          #+#    #+#             */
/*   Updated: 2024/12/12 17:32:20 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_cost
{
    int			cost;
    int			forward;
} t_cost;

typedef struct a_validnumber
{
	int			valid;
	long		number;
}t_validnumber;

//parsing functions
char	**param_parser(char **argv, int argc);
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
t_validnumber	ft_custom_atoi(const char *nptr);
char	**param_parser(char **argv, int argc);
char *ft_holy_joint(char **argv, int argc);
void    sort_list(t_stack **stack_a,t_stack **stack_b, int stack_elem);
void	sort_two(t_stack **stack);
void	sort_three(t_stack **stack);
void	sort_five(t_stack **stack_a,t_stack **stack_b, int stack_elem);
int		find_smallest(t_stack *stack);
int		find_largest(t_stack *stack);
int		find_position(t_stack *stack, int number);
t_cost	calculate_move_cost(int target_position, int stack_elem);
void	rotate_to_top(t_stack **stack, int target_position, void (*rotate)(t_stack **stack), void (*reverse_rotate)(t_stack **stack));
int		find_optimal_position(t_stack *stack, int number);
#endif