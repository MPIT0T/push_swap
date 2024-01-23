/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:26:20 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/23 20:50:54 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	ft_fill_stack(char **tab, t_stack **a, size_t n)
{
	size_t i;
	int tmp;
	t_stack	*node;

	i = 0;
	tmp = ft_atoi(tab[i++]);
	*a = ft_newelem(tmp);
	if (!(*a))
		return (1);
	while (i < n)
	{
		tmp = ft_atoi(tab[i++]);
		node = ft_newelem(tmp);
		if (!node)
			return (ft_free_stack(a), 1);
		ft_stackadd_back(a, node);
	}
	return (0);
}

t_stack	*ft_init_1arg(char *str)
{
	char	**tab;
	t_stack	*a;
	size_t	n;

	tab = ft_split(str, ' ');
	if (!tab)
		exit(1);		//TODO
	n = ft_tabsize(tab);
	if (ft_checktab(tab, n))
	{
		free(tab);
		ft_printf("Error\n");
		exit(1);
	}
	if (ft_fill_stack(tab, &a, n) == 1)
		return (ft_free_tab(tab), NULL);
	return (ft_free_tab(tab), a);
}

t_stack	*ft_init_narg(char **tab, size_t n)
{
	t_stack	*a;

	if (ft_checktab(tab, n))
	{
		ft_printf("Error\n");
		exit(1);
	}
	if (ft_fill_stack(tab, &a, n) == 1)
		return (NULL);
	return (a);
}
