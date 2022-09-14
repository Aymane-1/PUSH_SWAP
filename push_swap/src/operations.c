/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 04:59:51 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/13 09:18:02 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_frame *frame, int a_pair)
{
	t_stack		*a;
	int			len;

	a = frame->a;
	len = 0;
	if (a_pair > (find_stack_len(frame, 'a') / 2))
	{
		len = find_stack_len(frame, 'a') - a_pair;
		while (len--)
			do_rra(frame, 1);
	}
	else
	{
		len = a_pair;
		while (len--)
			do_ra(frame, 1);
	}
	do_pa(frame, 1);
}

static void	set_stacks(t_frame *frame, t_stack **a, t_stack **b)
{
	*a = frame->a;
	*b = frame->b;
}

void	check_rrr(t_frame *frame, long b_num, long b_pair)
{
	t_stack		*a;
	t_stack		*b;
	long		b_element;
	long		a_element;

	set_stacks(frame, &a, &b);
	b_element = b_num;
	a_element = b_pair;
	while (a->num != a_element && b->num != b_element)
	{
		do_rrr(frame);
		set_stacks(frame, &a, &b);
	}
	while (a->num != a_element)
	{
		do_rra(frame, 1);
		set_stacks(frame, &a, &b);
	}
	while (b->num != b_element)
	{
		do_rrb(frame, 1);
		set_stacks(frame, &a, &b);
	}
	do_pa(frame, 1);
}

void	check_rr(t_frame *frame, long b_num, long b_pair)
{
	t_stack		*a;
	t_stack		*b;
	long		b_element;
	long		a_element;

	set_stacks(frame, &a, &b);
	b_element = b_num;
	a_element = b_pair;
	while (a->num != a_element && b->num != b_element)
	{
		do_rr(frame);
		set_stacks(frame, &a, &b);
	}
	while (a->num != a_element)
	{
		do_ra(frame, 1);
		set_stacks(frame, &a, &b);
	}
	while (b->num != b_element)
	{
		do_rb(frame, 1);
		set_stacks(frame, &a, &b);
	}
	do_pa(frame, 1);
}

void	rotate_b(t_frame *frame, int b_element, int ind_of_pair)
{
	t_stack		*b;
	int			len;

	b = frame->b;
	len = 0;
	if (b_element > find_stack_len(frame, 'b') / 2)
	{
		len = find_stack_len(frame, 'b') - b_element;
		while (len--)
			do_rrb(frame, 1);
	}
	else
	{
		len = b_element;
		while (len--)
			do_rb(frame, 1);
	}
	rotate_a(frame, ind_of_pair);
}
