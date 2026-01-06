NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -I.
LIBFT		= ./libft/libft.a

SRC			=	argument_handling.c \
				ft_utils.c \
				ft_utils_stacks.c \
				push_movements.c \
				reverse_rotate_movements.c \
				rotate_movements.c \
				swap_movements.c \
				turkish_sort.c \
				sort_three.c \
				analysis_functions.c

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
