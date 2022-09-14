/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_del_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 01:35:28 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/13 09:08:12 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_del_top(t_frame *frame, char stack_name)
{
	t_stack		**top;
	t_stack		*tmp;

	if (stack_name == 'a')
		top = &frame->a;
	else
		top = &frame->b;
	if (*top)
	{
		if ((*top)->next == *top)
		{
			free(*top);
			*top = NULL;
		}
		else
		{
			tmp = *top;
			*top = (*top)->next;
			tmp->prev->next = *top;
			(*top)->prev = tmp->prev;
			free(tmp);
		}
	}
}
