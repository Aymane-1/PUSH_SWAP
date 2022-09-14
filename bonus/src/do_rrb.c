/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:45:51 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/08 01:32:16 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rrb(t_frame *frame, int flag)
{
	if (frame->b)
		frame->b = frame->b->prev;
	if (flag)
		write(1, "rrb\n", 4);
}
