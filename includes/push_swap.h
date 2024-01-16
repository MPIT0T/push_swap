/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:23:40 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/16 14:22:24 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
# define PUSH_SWAP_PUSH_SWAP_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				state;
	struct s_stack	*next;
} t_stack;

/*******************/
/*******RULES*******/
/*******************/

/*swap*/
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

/*push*/
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

/*rotate*/
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

/*reverse rotate*/
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

long	ft_atol(const char *nptr);

int		ft_checktab(char **tab, size_t n);
t_stack	*ft_init_narg(char **tab, size_t n);
t_stack	*ft_init_1arg(char *str);

t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_newelem(int value);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
#endif
