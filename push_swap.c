/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:21:09 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/11 11:39:51 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_stack	a;
	//t_stack	b;

	if (argc == 2)
	{
		a = ft_init_1arg(argv[1]);
	}
	else
	{
		a = ft_init_narg(&argv[1], argc - 1);
	}
	ft_printf("%d", a.top->content);
	ft_printf("%d", a.top->next->content);
	ft_printf("%d", a.top->next->next->content);
	return (0);
}