NAME = push_swap

PUSH_SWAP =	push_swap.c

SRCS = 			${PUSH_SWAP}

OBJS = 			${SRCS:.c=.o}

CFLAGS = 	-Wall -Werror -Wextra -fsanitize=address -g 

%.o:%.c		Makefile push_swap.h
			${CC} ${CFLAGS} -I ./ -c $< -o $@

${NAME}:	${OBJS} ${NAME}

all: 		${NAME}

clean:
			rm -f ${OBJS}

fclean:	clean;
			rm -f ${NAME}

re:	fclean all

.PHONY: 	all clean fclean re