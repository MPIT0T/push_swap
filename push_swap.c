/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:21:09 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/18 18:16:16 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_print(t_stack *a, t_stack *b)
{
	ft_printf("\na\n");
	while (a)
	{
		ft_printf("%d\n", a->value);
		a = a->next;
	}
	ft_printf("\nb\n");
	while (b)
	{
		ft_printf("%d\n", b->value);
		b = b->next;
	}
	ft_printf("\n");
}

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (argc == 2)
		a = ft_init_1arg(argv[1]);
	else
		a = ft_init_narg(&argv[1], argc - 1);
	b = NULL;
	ft_print(a, b);
	return (0);
}

/*int main(int argc, char **argv)
{
	(void) argc;
	char	**tab;

	tab = ft_split(argv[1], ' ');
	size_t	i = 0;
	while (tab[i])
		ft_printf("%s\n", tab[i++]);
	ft_printf("%s\n", tab[i]);
	return (0);
}*/
