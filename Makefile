NAME = push_swap

SRC = push_swap.c push_swap_utils.c ft_split.c ft_check_arguments.c

OBJ = $(SRC:.c = .o)

cc = cc

FLAGS = -Werror -Wextra -Wall

$(NAME) : $(OBJ)
	$(CC) $(OBJ) $(FLAGS) -o $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $<

clean :
	rm -rf $(OBJ)

fclean :
	rm -rf $(NAME)

re : fclean all
