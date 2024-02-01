/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:33:15 by mpitot            #+#    #+#             */
/*   Updated: 2024/02/01 15:29:36 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_next_to(t_stack *b, int num)
{
	int		biggest;
	int		bigbig;
	int		smallest;

	smallest = INT_MAX;
	biggest = INT_MIN;
	bigbig = INT_MIN;
	while (b)
	{
		if (b->value <= smallest)
			smallest = b->value;
		if (b->value >= bigbig)
			bigbig = b->value;
		if (b->value >= biggest && b->value < num)
			biggest = b->value;
		b = b->next;
	}
	if (smallest > num)
		return (bigbig);
	return (biggest);
}

static size_t	ft_rotations_b(t_stack *b, int num)
{
	size_t	i;
	int		next_to;
	t_stack	*tmp;

	i = 0;
	next_to = ft_get_next_to(b, num);
	tmp = b;
	while (tmp->value != next_to)
	{
		tmp = tmp->next;
		i++;
	}
	if (i <= (ft_stacklen(b) / 2) + 1)
		return (i);
	else
		return (ft_stacklen(b) - i);
}

static size_t	ft_rotations_a(t_stack *a, int num)
{
	size_t	i;
	t_stack	*tmp;

	i = 0;
	tmp = a;
	while (tmp->value != num)
	{
		tmp = tmp->next;
		i++;
	}
	if (i <= ft_stacklen(a) / 2 + 1)
		return (i);
	else
		return (ft_stacklen(a) - i);
}

int	ft_cheapest(t_stack *a, t_stack *b)
{
	int		cheapest;
	size_t	cur_count;
	size_t	sm_count;
	t_stack	*tmp;

	sm_count = SIZE_MAX;
	tmp = a;
	while (tmp)
	{
		cur_count = ft_rotations_a(a, tmp->value)
			+ ft_rotations_b(b, tmp->value) + 1;
		if (cur_count <= sm_count)
		{
			sm_count = cur_count;
			cheapest = tmp->value;
		}
		tmp = tmp->next;
	}
	return (cheapest);
}
