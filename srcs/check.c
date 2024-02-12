/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:55:36 by mpitot            #+#    #+#             */
/*   Updated: 2024/02/12 19:21:20 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	ft_tabsize(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_is_in_tab(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->value == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ft_checktab(char **tab, size_t n)
{
	long	num;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		if ((tab[i][j] == '-' || tab[i][j] == '+') && ft_strlen(tab[i]) != 1)
			j++;
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]))
				return (1);
			j++;
		}
		num = ft_atol(tab[i]);
		if (num > (long) INT_MAX || num < (long) INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_sort(t_stack *stack)
{
	int		prev;

	prev = INT_MIN;
	while (stack)
	{
		if (stack->value < prev)
			return (0);
		prev = stack->value;
		stack = stack->next;
	}
	return (1);
}
