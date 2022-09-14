/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:45:34 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/08 01:31:16 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pa(t_frame *frame, int flag)
{
	long int	tmp;

	if (frame->b)
	{
		tmp = frame->b->num;
		stack_del_top(frame, 'b');
		stack_add_top(frame, 'a', tmp);
	}
	if (flag)
		write(1, "pa\n", 3);
}
