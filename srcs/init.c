/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:26:20 by mpitot            #+#    #+#             */
/*   Updated: 2024/02/12 19:45:54 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_fill_stack(char **tab, t_stack **a, size_t n)
{
	size_t	i;
	int		tmp;
	t_stack	*node;

	i = 0;
	tmp = ft_atoi(tab[i++]);
	*a = ft_newelem(tmp);
	if (!(*a))
		return (1);
	while (i < n)
	{
		tmp = ft_atoi(tab[i++]);
		if (ft_is_in_tab(*a, tmp))
			return (ft_free_stack(a), 1);
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

	if (!str || !str[0])
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(1);
	}
	tab = ft_split(str, ' ');
	if (!tab)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(1);
	}
	n = ft_tabsize(tab);
	if (ft_checktab(tab, n))
	{
		ft_free_tab(tab);
		ft_putendl_fd("Error", STDERR_FILENO);
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
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(1);
	}
	if (ft_fill_stack(tab, &a, n) == 1)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(1);
	}
	return (a);
}
