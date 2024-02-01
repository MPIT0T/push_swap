/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:21:09 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/31 18:00:27 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
	{
		//ft_putstr_fd("Error\n", 2);
		exit(1);
	}
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
