/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 05:03:06 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/17 06:37:51 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	num_moves_completion(t_frame *frame, int b_index,
int b_ind_of_pair, int *b_moves)
{
	int	moves_a;
	int	moves_b;

	moves_a = 0;
	moves_b = 0;
	if (b_index <= find_stack_len(frame, 'b') / 2
		&& b_ind_of_pair >= find_stack_len(frame, 'a') / 2)
	{
		moves_b = b_index;
		moves_a = find_stack_len(frame, 'a') - b_ind_of_pair;
		*b_moves = (moves_a + moves_b) + 1;
	}
	else if (b_index >= find_stack_len(frame, 'b') / 2
		&& b_ind_of_pair <= find_stack_len(frame, 'a') / 2)
	{
		moves_a = b_ind_of_pair;
		moves_b = find_stack_len(frame, 'b') - b_index;
		*b_moves = (moves_a + moves_b) + 1;
	}
}

static void	ft_num_of_moves(t_frame *frame, int moves_a, int moves_b, int i)
{
	t_stack	*b;

	b = frame->b;
	i = find_stack_len(frame, 'b');
	while (i--)
	{
		ft_find_pair(frame, b->num);
		if (b->index <= find_stack_len(frame, 'b') / 2
			&& b->ind_of_pair <= find_stack_len(frame, 'a') / 2)
		{
			moves_b = b->index;
			moves_a = b->ind_of_pair;
			b->moves = ft_max(moves_a, moves_b) + 1;
		}
		else if (b->index >= find_stack_len(frame, 'b') / 2
			&& b->ind_of_pair >= find_stack_len(frame, 'a') / 2)
		{
			moves_a = find_stack_len(frame, 'a') - b->ind_of_pair;
			moves_b = find_stack_len(frame, 'b') - b->index;
			b->moves = ft_max(moves_a, moves_b) + 1;
		}
		else
			num_moves_completion(frame, b->index, b->ind_of_pair, &b->moves);
		b = b->next;
	}
}

void	initialisation(t_frame *frame)
{
	int	moves_a;
	int	moves_b;
	int	i;

	i = 0;
	moves_a = 0;
	moves_b = 0;
	ft_num_of_moves(frame, moves_a, moves_b, i);
}
