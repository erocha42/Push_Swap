NAME			= push_swap
NAME_CHECKER 	= checker
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g -I.
LIBFT			= ./libft/libft.a

SRC				=	PS/argument_handling.c \
					PS/ft_utils.c \
					PS/ft_utils_stacks.c \
					PS/push_movements.c \
					PS/reverse_rotate_movements.c \
					PS/rotate_movements.c \
					PS/swap_movements.c \
					PS/turkish_sort.c \
					PS/sort_three.c \
					PS/analysis_functions.c

SRC_CHECKER		=	PS/argument_handling.c \
					PS/push_movements.c \
					PS/reverse_rotate_movements.c \
					PS/rotate_movements.c \
					PS/swap_movements.c \
					PS/ft_utils_stacks.c \
					PS/ft_utils.c \
					GNL/get_next_line.c \
					GNL/get_next_line_utils.c \
					BONUS/checker_utils.c

OBJ				= $(SRC:.c=.o)
OBJ_CHECKER		= $(SRC_CHECKER:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) -g $(CFLAGS) $(OBJ) PS/main.c $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

bonus: $(NAME_CHECKER)
	
$(NAME_CHECKER): $(LIBFT) $(OBJ_CHECKER)
		$(CC) -g $(CFLAGS) $(OBJ_CHECKER) BONUS/checker.c $(LIBFT) -o $(NAME_CHECKER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ)
	rm -f $(OBJ_CHECKER)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)
	rm -f $(NAME_CHECKER)

re: fclean all

.PHONY: all clean fclean re bonus
