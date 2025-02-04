NAME = pipex

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = pipex.c pipex_pars.c pipex_exec_path.c pipex_free.c

LIBFT = libft/libft.a

OBJS = $(SRCS:.c=.o)

HEADER = pipex.h




all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
