/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:48:47 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/09 14:02:09 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	int		tmp;

	if (a != NULL && (*a)->next != NULL)
	{
		tmp = (*a)->value;
		(*a)->value = (*a)->next->value;
		(*a)->next->value = tmp;
	}
	ft_printf("sa");
}

void	sb(t_stack **b)
{
	int		tmp;

	if (b != NULL && (*b)->next != NULL)
	{
		tmp = (*b)->value;
		(*b)->value = (*b)->next->value;
		(*b)->next->value = tmp;
	}
	ft_printf("sb");
}

void	ss(t_stack **a, t_stack **b)
{
	int		tmp;

	if (a != NULL && (*a)->next != NULL)
	{
		tmp = (*a)->value;
		(*a)->value = (*a)->next->value;
		(*a)->next->value = tmp;
	}
	if (b != NULL && (*b)->next != NULL)
	{
		tmp = (*b)->value;
		(*b)->value = (*b)->next->value;
		(*b)->next->value = tmp;
	}
	ft_printf("ss");
}
