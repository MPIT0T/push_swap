/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:06:11 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/31 18:30:02 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_stack(t_stack **a)
{
	if (!(*a))
		return ;
	if ((*a)->next)
		ft_free_stack(&(*a)->next);
	free((*a));
}

t_stack	*ft_stacklast(t_stack *stack)
{
	int		i;

	if (!stack)
		return (NULL);
	i = 1;
	while (stack->next)
	{
		stack = stack->next;
		i++;
	}
	return (stack);
}

size_t	ft_stacklen(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack	*ft_newelem(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (*stack)
	{
		last = ft_stacklast(*stack);
		last->next = new;
	}
	else
		*stack = new;
}
