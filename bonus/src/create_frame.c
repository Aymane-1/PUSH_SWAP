/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:45:23 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/14 00:05:02 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_frame	*create_frame(t_frame *frame, char **argv)
{
	frame = (t_frame *)malloc(sizeof(t_frame));
	if (!frame)
		exit(1);
	frame->a = NULL;
	frame->b = NULL;
	frame->argv = argv;
	frame->line = NULL;
	frame->str = NULL;
	return (frame);
}
