/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:21:09 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/19 18:46:07 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_print(t_stack *a, t_stack *b)
{
	ft_printf("\n=A=\n");
	while (a)
	{
		ft_printf("%d\n", a->value);
		a = a->next;
	}
	ft_printf("\n=B=\n");
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
	if (!ft_is_sort(a, 0, ft_get_rank(a)))
		ft_sort(&a, &b, 0, ft_get_rank(a));
	ft_print(a, b);
	//ft_printf("%d", ft_is_sort(a, 0, ft_get_rank(a)));
	return (0);
}
