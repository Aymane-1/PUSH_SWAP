/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pairing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 22:42:52 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/13 23:53:55 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

static void	case_of_bigg_or_small(t_frame *frame, long b_num)
{
	t_stack	*b;
	int		len_b;

	b = frame->b;
	len_b = find_stack_len(frame, 'b');
	find_smallest(frame, 'a');
	while (len_b--)
	{
		if (b->num == b_num)
		{
			b->ind_of_pair = get_index(frame, frame->a->smallest, 'a');
			break ;
		}
		else
			b = b->next;
	}
}

static void	case_of_other_elements(t_frame *frame, long b_num, int index)
{
	t_stack	*a;
	t_stack	*b;
	int		len_b;

	a = frame->a;
	b = frame->b;
	len_b = find_stack_len(frame, 'b');
	while (len_b--)
	{
		if (b->num == b_num)
		{
			b->ind_of_pair = index;
			break ;
		}
		else
			b = b->next;
	}
}

void	ft_find_pair(t_frame *frame, long b_num)
{
	t_stack	*a;
	int		len_a;

	a = frame->a;
	ft_index_stack(frame);
	find_smallest(frame, 'a');
	find_biggest(frame, 'a');
	len_a = find_stack_len(frame, 'a');
	while (len_a--)
	{
		if (b_num > frame->a->biggest || b_num < frame->a->smallest)
			case_of_bigg_or_small(frame, b_num);
		else if (b_num > a->num && b_num < a->next->num)
			case_of_other_elements(frame, b_num, a->next->index);
		else
				a = a->next;
	}
}

void	determine_pair(t_frame *frame)
{
	t_stack	*a;
	t_stack	*b;
	int		len_b;
	int		len_a;

	a = frame->a;
	b = frame->b;
	len_b = find_stack_len(frame, 'b');
	while (len_b--)
	{
		ft_find_pair(frame, b->num);
		len_a = find_stack_len(frame, 'a');
		while (len_a--)
		{
			if (b->num > frame->a->biggest)
				b->pair = frame->a->smallest;
			else if (b->ind_of_pair == a->index)
				b->pair = a->num;
			else
				a = a->next;
		}
		b = b->next;
	}
}
