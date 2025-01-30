/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choosing_targets.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 03:25:46 by mohchaib          #+#    #+#             */
/*   Updated: 2025/01/26 03:41:53 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	helper_target_a(t_stack *a, t_stack *b, long *best_m, int b_elem)
{
	int	i;

	i = 0;
	while (i < b_elem)
	{
		if (b->nbr < a->nbr && b->nbr > *best_m)
		{
			*best_m = b->nbr;
			a->calcule->target = b;
		}
		b = b->next;
		i++;
	}
}

void	choose_target_a(t_stack *a, t_stack *b, int a_elem, int b_elem)
{
	long	best_match;
	int		i;

	i = 0;
	while (i < a_elem)
	{
		best_match = LONG_MIN;
		helper_target_a(a, b, &best_match, b_elem);
		if (best_match == LONG_MIN)
			a->calcule->target = find_largest(b);
		a = a->next;
		i++;
	}
}

static void	helper_target_b(t_stack *a, t_stack *b, long *best_m, int a_elem)
{
	int	i;

	i = 0;
	while (i < a_elem)
	{
		if (a->nbr > b->nbr && a->nbr < *best_m)
		{
			*best_m = a->nbr;
			b->calcule->target = a;
		}
		a = a->next;
		i++;
	}
}

void	choose_target_b(t_stack *a, t_stack *b, int a_elem, int b_elem)
{
	long	best_match;
	int		i;

	i = 0;
	while (i < b_elem)
	{
		best_match = LONG_MAX;
		helper_target_b(a, b, &best_match, a_elem);
		if (best_match == LONG_MAX)
			b->calcule->target = find_smallest(a);
		b = b->next;
		i++;
	}
}
