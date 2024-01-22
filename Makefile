NAME 		= 	push_swap

PUSH_SWAP 	= 	src/push_swap.c 	\
				src/check_args.c	\
				src/stack.c         \
				src/rotate.c        \
				src/push.c          \
				src/swap.c          \
				src/select_sort.c   \
				src/radix_sort.c    \
				src/lst_list.c      \
				src/utils.c

HEADERS 	= 	headers/push_swap.h 

SRCS 		= ${PUSH_SWAP}

OBJS 		= ${SRCS:.c=.o}

CC 			= gcc
CFLAGS 		= -Wall -Werror -Wextra -g

%.o:%.c 	Makefile headers/push_swap.h
			${CC} ${CFLAGS} -I ${HEADERS} -c $< -o $@

${NAME}: 	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all: 		${NAME}

clean:
			rm -f ${OBJS}

fclean: 	clean
			rm -f ${NAME}

re: 		fclean all

.PHONY: 	all clean fclean re
