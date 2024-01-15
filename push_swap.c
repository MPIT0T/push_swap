/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:21:09 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/15 17:44:55 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_stack	*a;
	//t_stack	b;

	if (argc == 2)
	{
		a = ft_init_1arg(argv[1]);
	}
	else
	{
		a = ft_init_narg(&argv[1], argc - 1);
	}
	ft_printf("%d\n", a->value);
	ft_printf("%d\n", a->next->value);
	ft_printf("%d\n", a->next->next->value);
	return (0);
}

/*

int		main(void)
{
	t_stack	a;
	int x = 3;
	int y = 2;

	a.size = 2;
	a.top = ft_lstnew((void *) &x);
	ft_lstadd_back(&a.top, ft_lstnew((void *) &y));
	ft_printf("%d", *(int *) a.top->next->content);
}
*/
