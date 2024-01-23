/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:45:31 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/23 15:27:40 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



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
	while (a->value != num)
	{
		a = a->next;
		i++;
	}
	if (i < ft_stacklen(a) / 2)
		return (i);
	else
		return (ft_stacklen(a) - i);
}

size_t	ft_place_count(t_stack *b, size_t num)
{
	size_t	values[3];
	t_stack	*tmp;

	values[0] = 0;
	values[1] = 0;
	values[2] = SIZE_MAX;
	tmp = b;
	while (tmp)
	{
		if (tmp->value < values[2])
			values[2] = tmp->value;
		if (tmp->value >= values[1] && tmp->value < num)
			values[1] = tmp->value;
		tmp = tmp->next;
	}
	tmp  = b;
	if (values[2] > num)
		values[1] = values[2];
	while (tmp->value != values[1])
	{
		tmp = tmp->next;
		values[0]++;
	}
	if (values[0] < ft_stacklen(b) / 2)
		return (values[0]);
	else
		return (ft_stacklen(b) - values[0]);
}

size_t	ft_cheapest(t_stack *a, t_stack *b)
{
	size_t	cheapest;
	size_t	sm_count;
	size_t	cur_count;

	sm_count = SIZE_MAX;
	while (a)
	{
		cur_count = ft_rotate_count(a, a->value) + ft_place_count(b, a->value) + 1;
		//ft_printf("%d\n", cur_count);
		if (cur_count <= sm_count)
			cheapest = a->value;
		a = a->next;
	}
	return (cheapest);
}

void	ft_put_on_top_a(t_stack **a, size_t num)
{
	size_t	i;
	t_stack	*tmp;

	i = 0;
	tmp = (*a);
	while (tmp->value != num)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < ft_stacklen(*a) / 2)
	{
		while ((*a)->value != num)
			ra(a);
	}
	else
	{
		while ((*a)->value != num)
			rra(a);
	}
}

void	ft_put_on_top_b(t_stack **a, int num)
{
	size_t	i;
	t_stack	*tmp;

	i = 0;
	tmp = (*a);
	while (tmp->value != num)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < ft_stacklen(*a) / 2)
	{
		while ((*a)->value != num)
			rb(a);
	}
	else
	{
		while ((*a)->value != num)
			rrb(a);
	}
}


size_t	ft_find_b(t_stack *b, int num)
{
	int	biggest;
	int	smallest;

	biggest = 0;
	smallest = INT_MAX;
	while (b)
	{
		if (b->value < smallest)
			smallest = b->value;
		if (b->value >= biggest && b->value < num)
			biggest = b->value;
		b = b->next;
	}
	if (smallest > num)
	{
		//ft_printf("%d\n", smallest);
		return (smallest);
	}
//	ft_printf("%d\n", biggest);
	return (biggest);
}

void	ft_push_n_place(t_stack **a, t_stack **b, int num)
{
	ft_put_on_top_a(a, num);
	ft_put_on_top_b(b, ft_find_b(*b, num));
	pb(a, b);
}

void	ft_cost_sort(t_stack **a, t_stack **b)
{
	int	cheapest;

	pb(a, b);
	pb(a, b);
	while(ft_stacklen(*a) > 3)
	{
		cheapest = ft_cheapest(*a, *b);
//		ft_printf("%d\n", cheapest);
		ft_push_n_place(a, b, cheapest);
	}
	/*ft_sort_three(a);
	ft_push_back(a, b);
	ft_rotate(a);*/
}
