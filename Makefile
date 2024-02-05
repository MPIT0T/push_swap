# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 12:46:44 by mpitot            #+#    #+#              #
#    Updated: 2024/02/05 13:23:44 by mpitot           ###   ########.fr        #
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

OBJS	=	$(SRCS:%.c=${OBJ_D}%.o)

OBJ_D	=	objs/

HEADER	=	push_swap.h

NAME	=	push_swap

CC		=	cc

FLAGS	=	-g3 -Wall -Wextra -Werror

all		:	${NAME}

${OBJS}	:	${OBJ_D}%.o: %.c libft/libft.h push_swap.h
	${CC} ${FLAGS} -c $< -o $@

${NAME}	:	${OBJ_D} ${OBJS} Makefile
	make bonus -C ./libft
	${CC} ${FLAGS} -o ${NAME} ${OBJS} -L./libft -lft

${OBJ_D}:
	@mkdir -p ${OBJ_D}

clean	:
	make clean -C ./libft
	rm -rf ${OBJ_D}

fclean	:	clean
	make fclean -C ./libft
	rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re bonus