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

void	sa(t_stack a)
{
	void	*tmp;

	if (a.top || a.top->next)
	{
		tmp = a.top->content;
		a.top->content = a.top->next->content;
		a.top->next->content = tmp;
	}
	ft_printf("sa");
}

void	sb(t_stack b)
{
	void	*tmp;

	if (b.top && b.top->next)
	{
		tmp = b.top->content;
		b.top->content = b.top->next->content;
		b.top->next->content = tmp;
	}
	ft_printf("sb");
}

void	ss(t_stack a, t_stack b)
{
	void	*tmp;

	if (a.top && a.top->next)
	{
		tmp = a.top->content;
		a.top->content = a.top->next->content;
		a.top->next->content = tmp;
	}
	if (b.top && b.top->next)
	{
		tmp = b.top->content;
		b.top->content = b.top->next->content;
		b.top->next->content = tmp;
	}
	ft_printf("ss");
}
