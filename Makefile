CC		=	cc

CFLAGS	=	-g #-Wall -Wextra -Werror

NAME	=	push_swap

SRCS	=	push_swap.c primal_actions.c a_actions.c b_actions.c double_actions.c utils.c prints.c cheat_sort.c parsing.c algo_funcs.c read.c small_sorts.c action_repeater.c

OBJS	=	${SRCS:.c=.o}

all		:	${NAME}

${NAME}	:	${OBJS}
			${MAKE} -C libft bonus
			${CC} ${CFLAGS} ${OBJS} -o ${NAME} -L./libft/ -lft

%.o		:	%.c
			$(CC) $(CFLAGS) $(EXTRA_FLAGS) -c $< -o $@

clean	:
			${MAKE} -C libft clean
			rm -rf ${OBJS}

fclean	:	clean
			${MAKE} -C libft fclean
			rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re
