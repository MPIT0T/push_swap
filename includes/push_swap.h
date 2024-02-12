/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:23:40 by mpitot            #+#    #+#             */
/*   Updated: 2024/02/12 18:57:33 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/incs/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

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
int		ft_strcmp(const char *s1, const char *s2);

/*create the stacks*/
int		ft_checktab(char **tab, size_t n);
size_t	ft_tabsize(char **tab);
int		ft_is_in_tab(t_stack *stack, int num);
t_stack	*ft_init_narg(char **tab, size_t n);
t_stack	*ft_init_1arg(char *str);

/*manipulate the stacks*/
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_newelem(int value);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
size_t	ft_stacklen(t_stack *stack);
void	ft_free_stack(t_stack **a);
int		ft_find_smallest(t_stack *x);

/*sorting*/
int		ft_is_sort(t_stack *stack);
void	ft_cost_sort(t_stack **a, t_stack **b);
void	ft_step(t_stack **a, t_stack **b, int cheapest);
int		ft_cheapest(t_stack *a, t_stack *b);
int		ft_get_next_to(t_stack *b, int num);
void	ft_rotate_a(t_stack **a, int cheapest);

void	print_list(t_stack *a, t_stack *b);

#endif
