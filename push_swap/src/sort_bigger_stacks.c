/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigger_stacks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 04:31:32 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/17 06:03:00 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_non_lis_to_b(t_frame *frame)
{
	t_stack	*a;
	int		len;

	len = find_stack_len(frame, 'a');
	ft_index_stack(frame);
	while (len--)
	{
		a = frame->a;
		if (a->mark == 1)
			do_ra(frame, 1);
		else
			do_pb(frame, 1);
		a = a->next;
	}
}

void	determine_lowest_to_push_to_a(t_frame *frame)
{
	t_stack	*b;
	int		len_b;
	int		node;

	b = frame->b;
	len_b = find_stack_len(frame, 'b');
	node = b->moves;
	while (len_b--)
	{
		if (b->moves < node)
			node = b->moves;
		b = b->next;
	}
	while (len_b--)
	{
		if (b->moves == node)
		{
			b->lowest = 1;
			return ;
		}
		b = b->next;
	}
}

void	last_sort(t_frame *frame)
{
	t_stack	*a;
	int		i;

	i = 0;
	a = frame->a;
	find_smallest(frame, 'a');
	i = get_index(frame, frame->a->smallest, 'a');
	if (i <= find_stack_len(frame, 'a') / 2)
		while (i--)
			do_ra(frame, 1);
	else
		while (i++ <= find_stack_len(frame, 'a') - 1)
			do_rra(frame, 1);
}

void	push_lowest_to_a(t_frame *frame)
{
	t_stack	*b;
	int		len_b;

	initialisation(frame);
	determine_lowest_to_push_to_a(frame);
	determine_pair(frame);
	b = frame->b;
	len_b = find_stack_len(frame, 'b');
	while (len_b--)
	{
		if (b->lowest == 1)
		{
			if (b->index <= find_stack_len(frame, 'b') / 2
				&& b->ind_of_pair <= find_stack_len(frame, 'a') / 2)
				check_rr(frame, b->num, b->pair);
			else if (b->index > find_stack_len(frame, 'b') / 2
				&& b->ind_of_pair > find_stack_len(frame, 'a') / 2)
				check_rrr(frame, b->num, b->pair);
			else
				rotate_b(frame, b->index, b->ind_of_pair);
			b = frame->b;
		}
		else
			b = b->next;
	}
}

void	sort_bigger_stacks(t_frame *frame)
{
	find_lis(frame);
	mark_lis(frame);
	push_non_lis_to_b(frame);
	while (find_stack_len(frame, 'b'))
		push_lowest_to_a(frame);
	last_sort(frame);
}
