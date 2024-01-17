/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:55:36 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/17 16:05:24 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_in_tab(char **tab, size_t n, char *elem)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (ft_strcmp(tab[i], elem) == 0)
			return (1);
		i++;
	}
	return (0);
}

int		ft_checktab(char **tab, size_t n)
{
	long	num;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		if (tab[i][j] == '-')
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
		if (ft_is_in_tab(&tab[i + 1], n - i - 1, tab[i]))
			return (1);
		i++;
	}
	return (0);
}
