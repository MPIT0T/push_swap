/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:23:40 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/20 17:55:51 by mpitot           ###   ########.fr       */
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
	size_t			rank;
	struct s_stack	*next;
} t_stack;

/*******************/
/***    RULES    ***/
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

/*******************/
/***             ***/
/*******************/

/*FTs*/
long	ft_atol(const char *nptr);
int	ft_strcmp(const char *s1, const char *s2);

/*create the stacks*/
int		ft_checktab(char **tab, size_t n);
size_t	ft_tabsize(char **tab);
t_stack	*ft_init_narg(char **tab, size_t n);
t_stack	*ft_init_1arg(char *str);

/*manipulate the stacks*/
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_newelem(int value);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
size_t	ft_stacklen(t_stack *stack);
void	ft_free_stack(t_stack **a);

/*sorting*/
int		ft_is_sort(t_stack *stack, char which);
void	ft_step_quicksort(t_stack **a, t_stack **b, size_t pivot);
void	ft_quicksort(t_stack **a, t_stack **b, size_t min, size_t max);
int		ft_is_pivot_sorted(t_stack *stack, size_t pivot);
size_t	ft_get_rank(t_stack *stack);

/*optimization*/
void	ft_put_pivot_down(t_stack **a, size_t	elem_rank);
void	ft_put_big_up(t_stack **b);




void	ft_print(t_stack *a, t_stack *b);

#endif
