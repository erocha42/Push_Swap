NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -I.
LIBFT		= ./libft/libft.a

SRC			=	argument_handling.c \
				ft_utils.c

OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) -g $(CFLAGS) $(OBJ) main.c $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
