/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:45:31 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/22 20:03:40 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_sort(t_stack *stack, char which)
{
	size_t	i;

	if (which == 'a')
	{
		i = 0;
		while (stack)
		{
			if (stack->rank != i)
				return (0);
			i++;
			stack = stack->next;
		}
	}
	else
	{
		i = ft_get_rank(stack);
		while (stack)
		{
			if (stack->rank != i)
				return (0);
			i--;
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


size_t	ft_rotate_count(t_stack *a, size_t num)
{
	size_t	i;

	i = 0;
	while (a->rank != num)
	{
		a = a->next;
		i++;
	}
	if (i < ft_stacklen(a) / 2)
		return (i);
	else
		return (ft_stacklen(a) - i);
}

size_t	ft_place_count(t_stack *a, size_t num)
{
	size_t	i;

	i = 0;
	while (a)
	{
		if (a->rank > num)
			break ;
		a = a->next;
		i++;
	}
	if (i < ft_stacklen(a) / 2)
		return (i);
	else
		return (ft_stacklen(a) - i);
}

size_t	ft_cheapest(t_stack *a, t_stack *b)
{
	size_t	cheapest;
	size_t	sm_count;
	size_t	cur_count;

	sm_count = SIZE_MAX;
	while (a)
	{
		cur_count = ft_rotate_count(a, a->rank) + ft_place_count(a, a->rank) + 1;
		if (cur_count <= sm_count)
			cheapest = a->rank;
		a = a->next;
	}
	return (cheapest);
}

void	ft_put_on_top(t_stack **a, size_t num)
{
	size_t	i;

	i = 0;
	while ((*a)->rank != num)
	{
		(*a) = (*a)->next;
		i++;
	}
	if (i < ft_stacklen(*a) / 2)
	{
		while ((*a)->rank != num)
			ra(a);
	}
	else
	{
		while ((*a)->rank != num)
			rra(a);
	}
}

void	ft_push_n_place(t_stack **a, t_stack **b, size_t num)
{
	ft_put_on_top(a, num);
	ft_place_b()
	pb(a, b);
}

void	ft_cost_sort(t_stack **a, t_stack **b)
{
	size_t	cheapest;

	pb(a, b);
	pb(a, b);
	while(ft_stacklen(*a) > 3)
	{
		cheapest = ft_cheapest(*a, *b);
		ft_push_n_place(a, b, cheapest);
	}
	ft_sort_three(a);
	ft_push_back(a, b);
	ft_rotate(a);
}

















void	ft_step_quicksort(t_stack **a, t_stack **b, size_t pivot)
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
		pa(a, b);
}

void	ft_quicksort(t_stack **a, t_stack **b, size_t min, size_t max)
{
	size_t	pivot;

	if (min < max)
	{
		pivot = (min + max) / 2;
		if (!ft_is_pivot_sorted(*a, pivot))
			ft_step_quicksort(a, b, pivot);
		ft_quicksort(a, b, min, pivot);
		ft_quicksort(a, b, pivot + 1, max);
	}
}

