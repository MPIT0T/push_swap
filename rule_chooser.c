/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_chooser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:39:57 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/20 17:24:26 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_pivot_down(t_stack **a, size_t	elem_rank)
{
	size_t	elem_i;
	t_stack	*tmp;

	elem_i = 0;
	tmp = (*a);
	while (tmp->rank != elem_rank)
	{
		tmp = tmp->next;
		elem_i++;
	}
	if (elem_i < (ft_stacklen(*a) / 2) - 1)
	{
		while ((ft_stacklast(*a))->rank != elem_rank)
			ra(a);
	}
	else
	{
		while ((ft_stacklast(*a))->rank != elem_rank)
			rra(a);
	}
}

size_t	ft_find_big(t_stack *b, size_t	big_rank)
{
	size_t	elem_i;
	size_t	i;

	big_rank = 0;
	elem_i = 0;
	i = 0;
	while (b)
	{
		if (b->rank > big_rank)
			elem_i = i;
		b = b->next;
		i++;
	}
	return (elem_i);
}

size_t	ft_get_big_rank(t_stack *b)
{
	size_t	big_rank;

	big_rank = 0;
	while (b)
	{
		if (b->rank > big_rank)
			big_rank = b->rank;
		b = b->next;
	}
	return (big_rank);
}

void	ft_put_big_up(t_stack **b)
{
	size_t	elem_i;
	size_t	big_rank;

	big_rank = ft_get_big_rank(*b);
	elem_i = ft_find_big(*b, big_rank);
	if (elem_i < ft_stacklen(*b) - 1)
	{
		while ((*b)->rank != big_rank)
			rb(b);
	}
	else
	{
		while ((*b)->rank != big_rank)
			rrb(b);
	}
}