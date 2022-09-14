/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 01:35:18 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/14 00:06:19 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_top(t_frame *frame, char stack_name, int num)
{
	t_stack		**top;

	if (stack_name == 'a')
		top = &frame->a;
	else
		top = &frame->b;
	*top = (t_stack *)malloc(sizeof(t_stack));
	if (!(*top))
		push_swap_error(frame);
	(*top)->next = *top;
	(*top)->prev = *top;
	(*top)->num = num;
}

void	stack_add_top(t_frame *frame, char stack_name, int num)
{
	t_stack		**top;
	t_stack		*tmp;

	if (stack_name == 'a')
		top = &frame->a;
	else
		top = &frame->b;
	if (*top)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		if (!tmp)
			push_swap_error(frame);
		tmp->next = *top;
		tmp->prev = (*top)->prev;
		(*top)->prev = tmp;
		tmp->prev->next = tmp;
		tmp->num = num;
		*top = (*top)->prev;
	}
	else
		case_top(frame, stack_name, num);
}
