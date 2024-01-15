/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:23:40 by mpitot            #+#    #+#             */
/*   Updated: 2024/01/15 17:28:37 by mpitot           ###   ########.fr       */
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




long	ft_atol(const char *nptr);

int		ft_checktab(char **tab, size_t n);
t_stack	*ft_init_narg(char **tab, size_t n);
t_stack	*ft_init_1arg(char *str);

t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_newelem(int value);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
#endif
