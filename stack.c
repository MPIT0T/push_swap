/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:26:20 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/09 17:22:15 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_checktab(char **tab)
{
	long	num;
	size_t	i;
	size_t	j;

	i = 0;
	while (tab[i])
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
		i++;
	}
	return (0);
}
/*

size_t	ft_tabsize(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_fill_lst(char **tab, t_list *lst)
{
	int		n;

	n = ft_atoi(tab[0]);

}

t_stack	ft_init_stack_a(char *str)
{
	char	**tab;
	t_stack	a;
	int		status;

	tab = ft_split(str, ' ');
	if (!tab)
		exit(1);
	if (ft_checktab(tab))
	{
		free(tab);
		exit(1);
	}
	ft_fill_lst(tab, a.top);

	a.size = ft_tabsize(tab);


	return (a);
}*/
