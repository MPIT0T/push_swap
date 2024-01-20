/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:45:31 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/20 18:32:12 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_sort(t_stack *stack, char which)
{
	size_t	tmp;

	if (which == 'a')
	{
		while (stack)
		{
			if (stack->rank < tmp)
				return (0);
			tmp = stack->rank;
			stack = stack->next;
		}
	}
	else
	{
		while (stack)
		{
			if (stack->rank > tmp)
				return (0);
			tmp = stack->rank;
			stack = stack->next;
		}
	}
	return (1);
}

int		ft_is_pivot_sorted(t_stack *stack, size_t pivot)
{
	while (stack->rank != pivot)
	{
		if (stack->rank > pivot)
			return (0);
		stack = stack->next;
	}
	stack = stack->next;
	while (stack)
	{
		if (stack->rank < pivot)
			return (0);
		stack = stack->next;
	}
	return (1);
}

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
	ft_put_pivot_down(a, pivot);
	while ((*a)->rank != pivot)
	{
		if ((*a)->rank < pivot)
			pb(a, b);
		else
			ra(a);
	}
	while ((*b))
	{
		ft_put_big_up(b);
		pa(a, b);
	}
}

void	ft_sort(t_stack **a, t_stack **b, size_t min, size_t max)
{
	size_t	pivot;

	if (min < max)
	{
		pivot = (min + max) / 2;
		if (!ft_is_pivot_sorted(*a, pivot))
			ft_step(a, b, pivot);
		ft_sort(a, b, min, pivot);
		ft_sort(a, b, pivot + 1, max);
	}
}