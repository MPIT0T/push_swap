/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:26:20 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/10 16:07:22 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		i++;
	}
	return (0);
}

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
	size_t	i;
	int		tmp;

	i = 0;
	tmp = ft_atoi(tab[i++]);
	lst = ft_lstnew((void *) &tmp);
	while (tab[i])
	{
		tmp = ft_atoi(tab[i++]);
		ft_lstadd_back(&lst, ft_lstnew((void *) &tmp));
	}
}

t_stack	ft_init_1arg(char *str)
{
	char	**tab;
	t_stack	a;

	tab = ft_split(str, ' ');
	if (!tab)
		exit(1);
	if (ft_checktab(tab, ft_tabsize(tab)))
	{
		free(tab);
		exit(1);
	}
	a.top = NULL;
	ft_fill_lst(tab, a.top);
	a.size = ft_tabsize(tab);
	free(tab);
	return (a);
}

t_stack	ft_init_narg(char **tab, size_t n)
{
	t_stack	a;
	if (ft_checktab(tab, n))
		exit(1);
	a.top = NULL;
	ft_fill_lst(tab, a.top);
	a.size = n;
	free(tab);
	return (a);
}