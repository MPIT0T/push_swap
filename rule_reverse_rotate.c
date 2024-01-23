/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:32:57 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/16 16:46:45 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*tmp;

	if ((*a) && (*a)->next)
	{
		tmp = (*a);
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next->next = (*a);
		(*a) = tmp->next;
		tmp->next = NULL;
		ft_printf("rra\n");
	}
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;

	if ((*b) && (*b)->next)
	{
		tmp = (*b);
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next->next = (*b);
		(*b) = tmp->next;
		tmp->next = NULL;
		ft_printf("rrb\n");
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if ((*a) && (*a)->next)
	{
		tmp = (*a);
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next->next = (*a);
		(*a) = tmp->next;
		tmp->next = NULL;
	}
	if ((*b) && (*b)->next)
	{
		tmp = (*b);
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next->next = (*b);
		(*b) = tmp->next;
		tmp->next = NULL;
	}
	ft_printf("rrr");
}
