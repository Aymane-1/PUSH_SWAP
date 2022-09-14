# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 17:05:37 by aechafii          #+#    #+#              #
#    Updated: 2022/09/14 04:00:37 by aechafii         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =   create_frame.c \
        do_pa.c \
        do_pb.c \
        do_ra.c \
        do_rb.c \
        do_rr.c \
        do_rra.c \
        do_rrb.c \
        do_rrr.c \
        do_sa.c \
        do_sb.c \
        do_ss.c \
 		fill_stack_a.c \
		find_biggest_smallest.c \
		find_stack_len.c \
		lis.c \
		num_moves.c \
		operations.c \
		print.c \
		push_swap_error.c \
		push_swap_free.c \
		push_swap_indexing.c \
		push_swap_pairing.c \
		push_swap.c \
		solve_5_or_less.c \
		solver.c \
		sort_bigger_stacks.c \
		sorted.c \
		stack_add_end.c \
		stack_add_top.c \
		stack_del_top.c

HEADER = include/push_swap.h

OBJ = $(addprefix obj/, $(SRC:.c=.o))

CC = cc

CFLAGS = -Wall -Wextra -Werror -I include

all: $(NAME)

$(NAME): $(OBJ)
	@ $(CC) $(OBJ) $(CFLAGS) -o $(NAME)
	@echo "\n\033[90;1;4mPUSH SWAP\033[0m \033[1;32mCOMPLETE!\033[0m\n"
		
obj/%.o : src/%.c $(HEADER)
	@mkdir -p obj
	@ printf "\033[1;36mCreating  ⥱\033[0m   📁 \033[1;92m"
	@ echo "$(notdir $@)" 
	@$(CC) $(CFLAGS) -c $< -o $@
	@ printf "\033[0m"

clean:
		@rm -rf $(OBJ)
		@echo "\n\033[1;34mOBJECT FILES\033[0m \033[1;32mCLEANED!\033[0m\n"

fclean: clean
		@rm -rf $(NAME) 
		@echo "\033[90;1;4mPUSH_SWAP\033[0m \033[34;1mEXECUTABLE\033[0m \033[1;31mREMOVED! \n \033[0m"
	
re: fclean all
