/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:45:37 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/14 00:21:57 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pb(t_frame *frame, int flag)
{
	long int	tmp;

	if (frame->a)
	{
		tmp = frame->a->num;
		stack_del_top(frame, 'a');
		stack_add_top(frame, 'b', tmp);
	}
	if (flag)
		write(1, "pb\n", 3);
}
