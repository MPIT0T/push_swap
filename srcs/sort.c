/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:31:38 by mpitot            #+#    #+#             */
/*   Updated: 2024/02/09 13:06:53 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_rotate_a(a, next_to);
		pa(a, b);
	}
}

void	ft_sort_three(t_stack **x)
{
	if ((*x)->value > (*x)->next->value)
	{
		if ((*x)->next->value > (*x)->next->next->value)
			return (sa(x), rra(x));
		if ((*x)->value > (*x)->next->next->value)
			return (ra(x));
		return (sa(x));
	}
	if ((*x)->next->value < (*x)->next->next->value)
		return ;
	if ((*x)->value > (*x)->next->next->value)
		return (rra(x));
	return (rra(x), sa(x));
}

void	ft_sort_five(t_stack **a, t_stack **b)
{
	while ((*a)->value != ft_find_smallest(*a))
		ft_rotate_a(a, ft_find_smallest(*a));
	pb(a, b);
	while ((*a)->value != ft_find_smallest(*a))
		ft_rotate_a(a, ft_find_smallest(*a));
	pb(a, b);
	ft_sort_three(a);
	pa(a, b);
	pa(a, b);
}

void	ft_cost_sort(t_stack **a, t_stack **b)
{
	if (ft_stacklen(*a) == 2)
		return (sa(a));
	if (ft_stacklen(*a) == 3)
		return (ft_sort_three(a));
	if (ft_stacklen(*a) == 5)
		return (ft_sort_five(a, b));
	pb(a, b);
	if (ft_stacklen(*a) > 4)
		pb(a, b);
	while (ft_stacklen(*a) > 3)
		ft_step(a, b, ft_cheapest(*a, *b));
	ft_sort_three(a);
	ft_push_back(a, b);
	ft_rotate_a(a, ft_find_smallest(*a));
}
