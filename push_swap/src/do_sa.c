/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:45:58 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/08 01:32:36 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_frame *frame, int flag)
{
	long int	tmp;

	if (frame->a && frame->a->next != frame->a)
	{
		tmp = frame->a->num;
		frame->a->num = frame->a->next->num;
		frame->a->next->num = tmp;
	}
	if (flag)
		write(1, "sa\n", 3);
}
