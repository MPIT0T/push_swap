/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:59:10 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/16 13:41:41 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if ((*b) != NULL)
	{
		tmp = (*b);
		(*b) = (*b)->next;
		tmp->next = (*a);
		(*a) = tmp;
	}
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if ((*a) != NULL)
	{
		tmp = (*a);
		(*a) = (*a)->next;
		tmp->next = (*b);
		(*b) = tmp;
	}
	ft_printf("pb\n");
}
