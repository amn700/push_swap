/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 07:24:02 by mohchaib          #+#    #+#             */
/*   Updated: 2025/01/28 07:24:02 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include <limits.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_cost	*calcule;
}	t_stack;

typedef struct s_cost
{
	int				cost;
	int				cheapest;
	int				abv_median;
	struct s_stack	*target;
}	t_cost;

typedef struct a_validnumber
{
	int			valid;
	long		number;
}	t_validnumber;

int				ft_is_space(char c);
int				empty_arg_check(char **argv, int argc);
char			**param_parser(char **argv, int argc);
char			*ft_holy_joint(char **argv, int argc);
int				check_input(char **str);
void			free_matrix(char **matrix);
t_stack			*stk_new(int nbr);
int				stk_add_front(t_stack *node, t_stack **stack, int *elements);
int				populate_stack(char **matrix, t_stack **stack, int *stack_elem);
t_validnumber	ft_custom_atoi(const char *nptr);
void			free_stack(t_stack **stack, int stack_elem);
void			fix_index(t_stack **stack, int *elements);
int				check_duplicates(t_stack *stack, int stack_elem);
void			stk_swap(t_stack *a, t_stack *b);
void			stk_rotate(t_stack **stack);
void			stk_rev_rotate(t_stack **stack);
void			stk_delfirst(t_stack **stack, int *stack_elem);
void			print_stack(t_stack *stack, int stack_elem);
void			median_cmp(t_stack *stack, int elem);
void			cost_calcule_a(t_stack *a, int a_elem, int b_elem);
void			rotate_both(t_stack **stack_a, t_stack **stack_b,
					t_stack *cheapest_node, int *tab);
void			rev_rotate_both(t_stack **stack_a, t_stack **stack_b,
					t_stack *cheapest_node, int *tab);
void			initialize_nodes_a(t_stack *a, t_stack *b,
					int a_elem, int b_elem);
void			initialize_nodes_b(t_stack *a, t_stack *b,
					int a_elem, int b_elem);
void			move_node_to_top(t_stack **stack, t_stack *cheapest, char name);
t_stack			*find_smallest(t_stack *stack);
t_stack			*find_largest(t_stack *stack);
void			whats_the_cheapest(t_stack *stack, int elem);
t_stack			*thats_the_cheapest(t_stack *stack, int stack_elem);
int				check_sorted(t_stack *stack, int stack_elem);
void			sort_three(t_stack **stack);
void			fix_sorted_stack(t_stack **stack_a);
void			sort_list(t_stack **stack_a, int *a_elem);
int				ft_strcmp(char *s1, char *s2);
int				swaps(char *line, t_stack*stack_a, t_stack*stack_b, int **tab);
int				rotations(char *line, t_stack**stack_a, t_stack**stack_b);
int				run_operations(t_stack **stack_a, int *a_elem,
					t_stack	**stack_b, int *b_elem);
void			choose_target_a(t_stack *a, t_stack *b, int a_elem, int b_elem);
void			choose_target_b(t_stack *a, t_stack *b, int a_elem, int b_elem);
void			move_a_to_b(t_stack **stack_a, t_stack **stack_b,
					int *a_elem, int *b_elem);
void			move_b_to_a(t_stack **stack_a, t_stack **stack_b,
					int *a_elem, int *b_elem);
void			swap_a(t_stack *stack, int print);
void			swap_b(t_stack *stack, int print);
void			swap_ss(t_stack *stacka, t_stack *stackb, int print);
void			push_a(t_stack **stacka, t_stack **stackb,
					int *a_elem, int *b_elem);
void			push_b(t_stack **stacka, t_stack **stackb,
					int *a_elem, int *b_elem);
void			rotate_a(t_stack **stacka, int print);
void			rotate_b(t_stack **stackb, int print);
void			rotate_rr(t_stack **stackb, t_stack **stacka, int print);
void			r_rotate_a(t_stack **stacka, int print);
void			r_rotate_b(t_stack **stackb, int print);
void			r_rotate_rr(t_stack **stacka, t_stack **stackb, int print);
void			push_a_bonus(t_stack **stacka, t_stack **stackb,
					int *a_elem, int *b_elem);
void			push_b_bonus(t_stack **stacka, t_stack **stackb,
					int *a_elem, int *b_elem);

#endif