/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 07:24:38 by mohchaib          #+#    #+#             */
/*   Updated: 2025/01/28 07:24:38 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	populate_stack(char **matrix, t_stack **stack, int *stack_elem)
{
	int				i;
	t_validnumber	number;

	i = 0;
	while (matrix[i])
	{
		number = ft_custom_atoi(matrix[i]);
		if (!number.valid || !stk_add_front(stk_new((int)number.number), stack,
				stack_elem))
			return (0);
		i++;
	}
	return (1);
}

t_validnumber	ft_custom_atoi(const char *nptr)
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
		if (total.number > 2147483648)
			return (total.valid = 0, total);
		nptr++;
	}
	total.number *= sign;
	if (total.number == 2147483648)
		return (total.valid = 0, total);
	return (total.valid = 1, total);
}

void	free_stack(t_stack **stack, int stack_elem)
{
	t_stack	*tmp;

	tmp = *stack;
	while (stack_elem > 0)
	{
		tmp = tmp->next;
		free((*stack)->calcule);
		free(*stack);
		*stack = tmp;
		stack_elem--;
	}
}

void	fix_index(t_stack **stack, int *elements)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (i < *elements)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

int	check_duplicates(t_stack *stack, int stack_elem)
{
	t_stack	*tmp;
	int		i;
	int		j;

	tmp = stack;
	i = 0;
	stack = stack->next;
	while (i < stack_elem - 1)
	{
		j = 0;
		while (j < stack_elem - 1)
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
