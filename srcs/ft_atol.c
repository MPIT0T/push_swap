/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:48:09 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/09 16:48:09 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_checker(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	if (c >= '0' && c <= '9')
		return (2);
	return (0);
}

long	ft_atol(const char *nptr)
{
	unsigned int	i;
	long			value;
	int				sign;

	i = 0;
	value = 0;
	sign = 1;
	while (ft_checker(nptr[i]) == 1)
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (ft_checker(nptr[i]) == 2)
	{
		value = value * 10 + nptr[i] - 48;
		i++;
	}
	return (value * sign);
}
