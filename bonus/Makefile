# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/11 06:09:32 by aechafii          #+#    #+#              #
#    Updated: 2022/09/14 04:01:08 by aechafii         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRC =   checker_utils.c \
        checker.c \
        create_frame.c \
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
		get_next_line_utils.c \
		get_next_line.c \
		push_swap_error.c \
		push_swap_free.c \
		stack_add_end.c \
		stack_add_top.c \
		stack_del_top.c \
					
HEADER = include/*.h

OBJ = $(addprefix obj/, $(SRC:.c=.o))

CC = cc

CFLAGS = -Wall -Wextra -Werror -I include

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJ)
	@ $(CC) $(OBJ) $(CFLAGS) -o $(NAME)
	@echo "\n\033[90;1;4mCHECKER\033[0m \033[1;32mCOMPLETE!\033[0m\n"
		
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
