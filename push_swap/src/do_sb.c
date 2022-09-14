/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:46:01 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/08 01:32:49 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sb(t_frame *frame, int flag)
{
	long int	tmp;

	if (frame->b && frame->b->next != frame->b)
	{
		tmp = frame->b->num;
		frame->b->num = frame->b->next->num;
		frame->b->next->num = tmp;
	}
	if (flag)
		write(1, "sb\n", 3);
}
