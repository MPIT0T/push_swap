/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:59:10 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/16 14:18:48 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*tmp;

	if ((*a) && (*a)->next)
	{
		tmp = (*a);
		(*a) = (*a)->next;
		tmp->next = NULL;
		ft_stackadd_back(a, tmp);
	}
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	t_stack	*tmp;

	if ((*b) && (*b)->next)
	{
		tmp = (*b);
		(*b) = (*b)->next;
		tmp->next = NULL;
		ft_stackadd_back(b, tmp);
	}
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if ((*a) && (*a)->next)
	{
		tmp = (*a);
		(*a) = (*a)->next;
		tmp->next = NULL;
		ft_stackadd_back(a, tmp);
	}
	if ((*b) && (*b)->next)
	{
		tmp = (*b);
		(*b) = (*b)->next;
		tmp->next = NULL;
		ft_stackadd_back(b, tmp);
	}
	ft_printf("rr\n");
}
