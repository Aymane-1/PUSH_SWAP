/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_stack_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 01:33:31 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/13 09:11:10 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_stack_len(t_frame *frame, char stack_name)
{
	t_stack	*stack;
	t_stack	*end;
	int		len;

	if (stack_name == 'a')
		stack = frame->a;
	else
		stack = frame->b;
	len = 0;
	if (stack)
	{	
		if (stack_name == 'a')
			end = frame->a->prev;
		else
			end = frame->b->prev;
	}
	while (stack)
	{
		len++;
		if (stack == end)
			break ;
		stack = stack->next;
	}
	return (len);
}
