NAME = pipex

CC = cc

CFLAGS = -Wall -Werror -Wextra

CFILES = pipex.c pipex_utils.c libft/libft.a

OFILES = $(CFILES:.c=.o)

HEADER = pipex.h

all : $(NAME)

$(NAME) : $(OFILES) $(HEADER)
	$(CC) $(CFLAGS)  $(OFILES) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)


re: fclean all

.PHONY : all clean fclean re
