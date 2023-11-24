NAME = push_swap

PUSH_SWAP = push_swap.c check_args.c

HEADERS = push_swap.h

SRCS = ${PUSH_SWAP}

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g

%.o: %.c Makefile push_swap.h constants.h
	${CC} ${CFLAGS} -I ${HEADERS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re