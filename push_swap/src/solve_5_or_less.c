/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_5_or_less.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:44:23 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/17 05:49:24 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solve_2(t_frame *frame)
{
	if (frame->a->num > frame->a->next->num)
		do_sa(frame, 1);
}

static void	solve_3(t_frame *frame)
{
	int	i;

	find_biggest(frame, 'a');
	i = get_index(frame, frame->a->biggest, 'a');
	if (i < find_stack_len(frame, 'a') / 2)
		do_ra(frame, 1);
	else if (i >= find_stack_len(frame, 'a') / 2)
		while (i++ < find_stack_len(frame, 'a') - 1)
			do_rra(frame, 1);
	if (frame->a->num > frame->a->next->num)
		do_sa(frame, 1);
}

static void	solve_4(t_frame *frame)
{
	find_smallest(frame, 'a');
	if (frame->a->smallest == frame->a->prev->num)
	{	
		do_rra(frame, 1);
		do_pb(frame, 1);
	}
	else if (frame->a->smallest == frame->a->num)
		do_pb(frame, 1);
	else if (frame->a->smallest == frame->a->next->num)
	{	
		do_ra(frame, 1);
		do_pb(frame, 1);
	}
	else
	{
		do_rra(frame, 1);
		do_rra(frame, 1);
		do_pb(frame, 1);
	}
	solve_3(frame);
	do_pa(frame, 1);
}

static void	solve_5(t_frame *frame)
{
	t_stack	*a;
	int		i;

	a = frame->a;
	find_smallest(frame, 'a');
	i = get_index(frame, frame->a->smallest, 'a');
	if (i < 3)
		while (i--)
			do_ra(frame, 1);
	else if (i > find_stack_len(frame, 'a') / 2)
		while (i++ < find_stack_len(frame, 'a'))
			do_rra(frame, 1);
	do_pb(frame, 1);
	solve_4(frame);
	do_pa(frame, 1);
}

void	solve_5_or_less(t_frame *frame)
{
	if (find_stack_len(frame, 'a') == 2)
		solve_2(frame);
	else if (find_stack_len(frame, 'a') == 3)
		solve_3(frame);
	else if (find_stack_len(frame, 'a') == 4)
		solve_4(frame);
	else if (find_stack_len(frame, 'a') == 5)
		solve_5(frame);
}
