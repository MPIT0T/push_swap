/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:21:09 by mpitot            #+#    #+#             */
/*   Updated: 2024/02/08 22:52:26 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *a, t_stack *b)
{
	ft_printf("liste A:\n");
	while (a)
	{
		ft_printf("\t%i\n", a->value);
		a = a->next;
	}
	ft_printf("liste B:\n");
	if (!b)
	{
		ft_printf("\tNULL\n");
	}
	while (b)
	{
		ft_printf("\t%i\n", b->value);
		b = b->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		exit(1);
	if (argc == 2)
		a = ft_init_1arg(argv[1]);
	else
		a = ft_init_narg(&argv[1], argc - 1);
	b = NULL;
	if (ft_is_sort(a) == 0)
		ft_cost_sort(&a, &b);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
