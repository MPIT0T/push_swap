/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:21:09 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/17 16:56:24 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_print(t_stack **a, t_stack **b)
{
	t_stack	*tmpa;
	t_stack	*tmpb;

	tmpa = *a;
	tmpb = *b;
	ft_printf("\na\n");
	while (tmpa)
	{
		ft_printf("%d\n", tmpa->value);
		tmpa = tmpa->next;
	}
	ft_printf("\nb\n");
	while (tmpb)
	{
		ft_printf("%d\n", tmpb->value);
		tmpb = tmpb->next;
	}
	ft_printf("\n");
}


int		main(int argc, char **argv)
{
	t_stack	*a;
	//t_stack	*b;

	if (argc == 2)
	{
		a = ft_init_1arg(argv[1]);
	}
	else
	{
		a = ft_init_narg(&argv[1], argc - 1);
	}
	//b = NULL;
	ft_printf("%d", ft_is_sort(a, 'b'));
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
