/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:45:00 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/11 03:02:45 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solver(t_frame *frame)
{
	if (!(sorted(frame)))
	{
		if (find_stack_len(frame, 'a') <= 5)
			solve_5_or_less(frame);
		else if (find_stack_len(frame, 'a') > 5)
			sort_bigger_stacks(frame);
	}
}
