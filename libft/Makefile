NAME	=	libft.a

CC	= cc

CCFLAGS	= -Wall -Wextra -Werror

SRC = ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strcmp.c

OBJ = $(SRC:.c=.o)

AR = ar rcs


all	:	${NAME}

$(NAME)	:	$(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o : %.c libft.h
	$(CC) $(CCFLAGS) -c $< -o $@

clean	:
		rm	-rf	$(OBJ)

fclean	:	clean
		rm -rf $(NAME)

re	:	fclean	all

.PHONY : all bonus clean fclean re
