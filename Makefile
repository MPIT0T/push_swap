# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 12:46:44 by mpitot            #+#    #+#              #
#    Updated: 2024/02/19 15:21:40 by mpitot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	push_swap.c				\
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

${OBJS}	:	${OBJ_D}%.o: ${SRC_D}%.c libft/incs/libft.h includes/push_swap.h libft/libft.a
	${CC} ${FLAGS} -c $< -o $@

${NAME}	:	${OBJ_D} ${OBJS} Makefile libft/incs/libft.h includes/push_swap.h
	${CC} ${FLAGS} -o ${NAME} ${OBJS} -L./libft -lft

${OBJ_D}:
	@mkdir -p ${OBJ_D}

clean	:
	@echo "libft :"
	@make --no-print-directory clean -C ./libft
	@echo "push_swap :"
	rm -rf ${OBJ_D}

fclean	:
	@echo "libft :"
	@make --no-print-directory fclean -C ./libft
	@echo "push_swap :"
	rm -rf ${OBJ_D}
	rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re