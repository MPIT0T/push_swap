/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:26:20 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/15 17:43:35 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_tabsize(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_fill_stack(char **tab, t_stack **a, size_t n)
{
	size_t i;
	int tmp;

	i = 0;
	tmp = ft_atoi(tab[i++]);
	*a = ft_newelem(tmp);
	if (!(*a))
		return;
	while (i < n)
	{
		tmp = ft_atoi(tab[i++]);
		ft_stackadd_back(a, ft_newelem(tmp));
	}
}

t_stack	*ft_init_1arg(char *str)
{
	char	**tab;
	t_stack	*a;
	size_t	n;

	tab = ft_split(str, ' ');
	if (!tab)
		exit(1);
	n = ft_tabsize(tab);
	if (ft_checktab(tab, n))
	{
		free(tab);
		exit(1);
	}
	ft_fill_stack(tab, &a, n);
	free(tab);
	return (a);
}

t_stack	*ft_init_narg(char **tab, size_t n)
{
	t_stack	*a;

	if (ft_checktab(tab, n))
		exit(1);
	ft_fill_stack(tab, &a, n);
	return (a);
}