NAME			= push_swap
NAME_CHECKER 	= checker
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g -I.
LIBFT			= ./libft/libft.a

SRC				=	argument_handling.c \
					ft_utils.c \
					ft_utils_stacks.c \
					push_movements.c \
					reverse_rotate_movements.c \
					rotate_movements.c \
					swap_movements.c \
					turkish_sort.c \
					sort_three.c \
					analysis_functions.c

SRC_CHECKER		=	argument_handling.c \
					push_movements.c \
					reverse_rotate_movements.c \
					rotate_movements.c \
					swap_movements.c \
					ft_utils_stacks.c \
					ft_utils.c \
					GNL/get_next_line.c \
					GNL/get_next_line_utils.c

OBJ				= $(SRC:.c=.o)
OBJ_CHECKER		= $(SRC_CHECKER:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) -g $(CFLAGS) $(OBJ) main.c $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

bonus: $(NAME_CHECKER)
	
$(NAME_CHECKER): $(LIBFT) $(OBJ_CHECKER)
		$(CC) -g $(CFLAGS) $(OBJ_CHECKER) checker.c $(LIBFT) -o $(NAME_CHECKER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ)
	rm -f $(OBJ_CHECKER)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)
	rn -f $(NAME_CHECKER)

re: fclean all

.PHONY: all clean fclean re bonus
