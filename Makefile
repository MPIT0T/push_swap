# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 12:46:44 by mpitot            #+#    #+#              #
#    Updated: 2024/01/23 20:53:12 by mpitot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	push_swap.c	\
rule_swap.c				\
ft_atol.c				\
init.c					\
t_stack.c				\
rule_push.c				\
rule_rotate.c			\
rule_reverse_rotate.c	\
sort.c					\
check.c					\
ft_strcmp.c				\
calculations.c			\
step.c

OBJS	=	$(SRCS:.c=.o)

HEADER	=	push_swap.h

NAME	=	push_swap

CC		=	cc

FLAGS	=	-g3 -Wall -Wextra -Werror

all		:	${NAME}

%.o		:	%.c libft/libft.h printf/ft_printf.h push_swap.h
	${CC} ${FLAGS} -c $< -o $@

${NAME}	:	${OBJS} Makefile
	make bonus -C ./libft
	make -C ./printf
	${CC} ${FLAGS} -o ${NAME} ${OBJS} -L./libft -lft -L./printf -lftprintf

clean	:
	make clean -C ./libft
	make clean -C ./printf
	rm -f ${OBJS} ${B_OBJS}

fclean	:	clean
	make fclean -C ./libft
	make fclean -C ./printf
	rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re bonus