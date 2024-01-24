/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:00:03 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/23 16:59:36 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_stack **a, int cheapest)
{
	size_t	i;
	t_stack	*tmp;

	i = 0;
	tmp = *a;
	while (tmp->value != cheapest)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < ft_stacklen(*a) / 2)
	{
		while ((*a)->value != cheapest)
			ra(a);
	}
	else
	{
		while ((*a)->value != cheapest)
			rra(a);
	}
}

void	ft_rotate_b(t_stack **b, int cheapest)
{
	size_t	i;
	int		next_to;
	t_stack	*tmp;

	i = 0;
	next_to = ft_get_next_to(*b, cheapest);
	tmp = *b;
	while (tmp->value != next_to)
	{
		tmp = tmp->next;
		i++;
	}
	if (i <= ft_stacklen(*b) / 2)
	{
		while ((*b)->value != next_to)
			rb(b);
	}
	else
	{
		while ((*b)->value != next_to)
			rrb(b);
	}
}

void	ft_step(t_stack **a, t_stack **b, int cheapest)
{
	ft_rotate_a(a, cheapest);
	ft_rotate_b(b, cheapest);
	pb(a, b);
}
