CC			=	cc

CFLAGS		=	-g #-Wall -Wextra -Werror

NAME		=	push_swap

BONUS_SRCS	=	bonus_src/checker.c src/primal_actions.c bonus_src/sa_actions.c bonus_src/sb_actions.c bonus_src/sdouble_actions.c src/utils.c src/prints.c src/parsing.c

BONUS_OBJS	=	${BONUS_SRCS:.c=.o}

SRCS		=	src/push_swap.c src/primal_actions.c src/a_actions.c src/b_actions.c src/double_actions.c src/utils.c src/prints.c src/parsing.c src/action_repeater.c

OBJS		=	${SRCS:.c=.o}

all			:	${NAME}

${NAME}		:	${OBJS}
				${MAKE} -C libft bonus
				${CC} ${CFLAGS} ${OBJS} -o ${NAME} -L./libft/ -lft

bonus		:	${BONUS_OBJS}
				${MAKE} -C libft bonus
				${CC} ${CFLAGS} ${BONUS_OBJS} -o checker -L./libft/ -lft

%.o			:	%.c
				${CC} ${CFLAGS} ${EXTRA_FLAGS} -c $< -o $@

clean		:
				${MAKE} -C libft clean
				rm -rf ${OBJS}

fclean		:	clean
				${MAKE} -C libft fclean
				rm -f ${NAME}

re			:	fclean all

.PHONY		:	all clean fclean re
