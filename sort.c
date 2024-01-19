/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:45:31 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/19 19:01:03 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_sort(t_stack *stack, size_t min, size_t max)
{
	int		tmp;

	(void) max;
	tmp = stack->value;
	while (stack->rank != min)
		stack = stack->next;
	while (stack && stack->rank != max)
	{
		if (stack->value < tmp || stack->rank != min)
			return (0);
		tmp = stack->value;
		stack = stack->next;
		min++;
	}
	return (1);
}

/*

int		ft_sorted(t_stack *stack, size_t min, size_t max)
{

}

*/

size_t	ft_get_rank(t_stack *stack)
{
	size_t	rank;

	rank = 0;
	while (stack)
	{
		if (stack->rank > rank)
			rank = stack->rank;
		stack = stack->next;
	}
	return (rank);
}

void	ft_step(t_stack **a, t_stack **b, size_t pivot)
{
	int		nb;

	while ((*a)->rank != pivot)
		ra(a);
	nb = (*a)->value;
	ra(a);
	while ((*a)->rank != pivot)
	{
		if ((*a)->value < nb)
			pb(a, b);
		else
			ra(a);
	}
	while ((*b))
		pa(a, b);
}

void	ft_sort(t_stack **a, t_stack **b, size_t min, size_t max)
{
	size_t	pivot;

	if (min < max)
	{
		pivot = (min + max) / 2;
		ft_step(a, b, pivot);
		if (!ft_is_sort(*a, min, pivot))
			ft_sort(a, b, min, pivot);
		if (!ft_is_sort(*a, pivot + 1, max))
			ft_sort(a, b, pivot + 1, max);
	}
}