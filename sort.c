/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:31:38 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/24 14:24:34 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_smallest(t_stack *a)
{
	int		smallest;

	smallest = INT_MAX;
	while (a)
	{
		if (a->value < smallest)
			smallest = a->value;
		a = a->next;
	}
	return (smallest);
}

int	ft_get_position(t_stack *a, int num)
{
	int		next_to;
	int		biggest;
	int		smallest;

	next_to = INT_MAX;
	biggest = INT_MIN;
	smallest = INT_MAX;
	while (a)
	{
		if (a->value > biggest)
			biggest = a->value;
		if (a->value < next_to && a->value > num)
			next_to = a->value;
		if (a->value < smallest)
			smallest = a->value;
		a = a->next;
	}
	if (num > biggest)
		return (smallest);
	return (next_to);
}

void	ft_push_back(t_stack **a, t_stack **b)
{
	int		next_to;

	while ((*b))
	{
		next_to = ft_get_position(*a, (*b)->value);
		while ((*a)->value != next_to)
			rra(a);
		pa(a, b);
	}
}

void	ft_sort_three(t_stack **a)
{
	if (ft_is_sort(*a))
		return ;
	if ((*a)->value > (*a)->next->value)
	{
		if ((*a)->next->value > (*a)->next->next->value)
			return (sa(a), rra(a));
		if ((*a)->value < (*a)->next->next->value)
			return (sa(a));
		return (ra(a));
	}
	else
	{
		if ((*a)->value > (*a)->next->next->value)
			return ;
		else
			return (sa(a), ra(a));
	}
}

void	ft_cost_sort(t_stack **a, t_stack **b)
{
	if (ft_stacklen(*a) == 2)
	{
		if ((*a)->value > (*a)->next->value)
			return (sa(a));
		return ;
	}
	if (ft_stacklen(*a) == 3)
		return (ft_sort_three(a), ft_rotate_a(a, ft_find_smallest(*a)));
	pb(a, b);
	if (ft_stacklen(*a) > 4)
		pb(a, b);
	while (ft_stacklen(*a) > 3)
		ft_step(a, b, ft_cheapest(*a, *b));
	ft_sort_three(a);
	ft_push_back(a, b);
	ft_rotate_a(a, ft_find_smallest(*a));
}
