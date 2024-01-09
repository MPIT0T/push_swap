/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:59:10 by mpitot            #+#    #+#             */
/*   Updated: 2023/12/23 19:51:52 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pop(t_stack s)
{
	int		res;

	res = s.stack[0];
	ft_memmove(s.stack, &s.stack[1], --s.size);
	return (res);
}

void	pa()