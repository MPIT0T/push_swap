# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 12:46:44 by mpitot            #+#    #+#              #
#    Updated: 2024/02/09 13:49:35 by mpitot           ###   ########.fr        #
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

SRC_D	=	srcs/

OBJ_D	=	objs/

HEAD	=	includes/

NAME	=	push_swap

CC		=	cc

FLAGS	=	-Wall -Wextra -Werror -Iincludes

all		:
	@make --no-print-directory bonus -C libft/
	@make --no-print-directory ${NAME}

${OBJS}	:	${OBJ_D}%.o: ${SRC_D}%.c libft/libft.h ${HEAD}
	${CC} ${FLAGS} -c $< -o $@

${NAME}	:	${OBJ_D} ${OBJS} Makefile
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