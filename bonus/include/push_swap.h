/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 06:10:15 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/14 08:11:40 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

/*
** circular doubly-linked list
*/

typedef struct s_stack
{
	long			num;
	int				lis;
	int				mark;
	int				ind_of_pair;
	long			pair;
	long			smallest;
	long			biggest;
	int				index;
	int				moves;
	int				lowest;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

/*
** typedef for stacks a + b
*/

typedef struct _frame
{
	struct s_stack	*a;
	struct s_stack	*b;

	char			**argv;
	char			*line;
	char			*str;
}					t_frame;

/*
** checker functions
*/

int					sorted(t_frame *frame);
void				check_rrr(t_frame *frame, long b_num, long b_pair);
void				check_rr(t_frame *frame, long b_num, long b_pair);
void				read_instructions(t_frame *frame);
int					ft_isdigit(int c);
long				atoi_push_swap(char *str);
int					sorted(t_frame *frame);
char				*ft_is_read(char *str, int fd);
char				*get_next_line(int fd);
void				fill_stack_a_c(t_frame *frame);

/*
** utils functions
*/

t_frame				*create_frame(t_frame *frame, char **argv);
void				do_pa(t_frame *frame, int flag);
void				do_pb(t_frame *frame, int flag);
void				do_ra(t_frame *frame, int flag);
void				do_rb(t_frame *frame, int flag);
void				do_rr(t_frame *frame, int flag);
void				do_rra(t_frame *frame, int flag);
void				do_rrb(t_frame *frame, int flag);
void				do_rrr(t_frame *frame, int flag);
void				do_sa(t_frame *frame, int flag);
void				do_sb(t_frame *frame, int flag);
void				do_ss(t_frame *frame, int flag);
void				fill_stack_a(t_frame *frame);
void				push_swap_error(t_frame *frame);
void				push_swap_free(t_frame *frame);
void				stack_add_end(t_frame *frame, char stack_name, int num);
void				stack_del_top(t_frame *frame, char stack_name);
void				stack_add_top(t_frame *frame, char stack_name, int num);

#endif
