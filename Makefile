NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = $(wildcard *.c)

OBJS = $(SRCS:%.c=build/%.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

build/%.o: %.c
	mkdir -p build
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf  build

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re