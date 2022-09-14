/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest_smallest.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:44:45 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/11 06:02:21 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_smallest(t_frame *frame, char stack_name)
{
	t_stack		*stack;
	t_stack		*tmp;
	t_stack		*end;

	if (stack_name == 'a')
		stack = frame->a;
	else
		stack = frame->b;
	tmp = stack;
	if (stack_name == 'a')
		end = frame->a->prev;
	else
		end = frame->b->prev;
	stack->smallest = tmp->num;
	while (1)
	{
		if (tmp->num <= stack->smallest)
			stack->smallest = tmp->num;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
}

void	find_biggest(t_frame *frame, char stack_name)
{
	t_stack		*stack;
	t_stack		*tmp;
	t_stack		*end;

	if (stack_name == 'a')
		stack = frame->a;
	else
		stack = frame->b;
	tmp = stack;
	if (stack_name == 'a')
		end = frame->a->prev;
	else
		end = frame->b->prev;
	stack->biggest = tmp->num;
	while (1)
	{
		if (tmp->num > stack->biggest)
			stack->biggest = tmp->num;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
}
