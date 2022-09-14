/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:45:49 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/08 01:32:03 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rra(t_frame *frame, int flag)
{
	if (frame->a)
		frame->a = frame->a->prev;
	if (flag)
		write(1, "rra\n", 4);
}
