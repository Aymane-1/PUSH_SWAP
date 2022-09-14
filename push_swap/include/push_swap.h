/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:44:51 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/14 07:34:31 by aechafii         ###   ########.fr       */
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

typedef struct s_frame
{
	struct s_stack	*a;
	struct s_stack	*b;

	char			**argv;
	char			*line;
	char			*str;
}					t_frame;

/*
** push_swap functions
*/

void				find_biggest(t_frame *frame, char stack_name);
void				find_smallest(t_frame *frame, char stack_name);
int					find_stack_len(t_frame *frame, char stack_name);
void				sort_bigger_stacks(t_frame *frame);
void				solve_5_or_less(t_frame *frame);
void				solver(t_frame *frame);
int					sorted(t_frame *frame);
void				ft_init_lis(t_frame *frame);
int					ft_max(int a, int b);
int					ft_isdigit(int c);
void				find_lis(t_frame *frame);
void				mark_lis(t_frame *frame);
int					get_index(t_frame *frame, int value, char stack_name);
void				ft_put_index(int *ind, int i);
void				ft_index_stack(t_frame *frame);
void				ft_find_pair(t_frame *frame, long b_num);
void				determine_pair(t_frame *frame);
void				initialisation(t_frame *frame);
void				rotate_a(t_frame *frame, int a_pair);
void				check_rrr(t_frame *frame, long b_num, long b_pair);
void				check_rr(t_frame *frame, long b_num, long b_pair);
void				rotate_b(t_frame *frame, int b_element, int ind_of_pair);
void				last_sort(t_frame *frame);

t_frame				*create_frame(t_frame *frame, char **argv);
void				do_pa(t_frame *frame, int flag);
void				do_pb(t_frame *frame, int flag);
void				do_ra(t_frame *frame, int flag);
void				do_rb(t_frame *frame, int flag);
void				do_rr(t_frame *frame);
void				do_rra(t_frame *frame, int flag);
void				do_rrb(t_frame *frame, int flag);
void				do_rrr(t_frame *frame);
void				do_sa(t_frame *frame, int flag);
void				do_sb(t_frame *frame, int flag);
void				do_ss(t_frame *frame, int flag);
void				fill_stack_a(t_frame *frame);
void				push_swap_error(t_frame *frame);
void				push_swap_free(t_frame *frame);
void				stack_add_end(t_frame *frame, char stack_name, int num);
void				stack_del_top(t_frame *frame, char stack_name);
void				stack_add_top(t_frame *frame, char stack_name, int num);
void				print_stacks(t_frame *frame);
void				print_list(t_frame *frame);
void				print_lis_and_mark(t_frame *frame);

#endif
