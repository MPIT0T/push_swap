/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:45:31 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/17 16:57:58 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_sort(t_stack *stack, char which)
{
	int		tmp;

	tmp = stack->value;
	while (stack)
	{
		if (stack->value > tmp && which == 'b')
			return (0);
		if (stack->value < tmp && which == 'a')
			return (0);
		tmp = stack->value;
		stack = stack->next;
	}
	return (1);
}
