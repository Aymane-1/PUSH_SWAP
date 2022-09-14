/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_indexing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 04:55:28 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/13 22:47:31 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_frame *frame, int value, char stack_name)
{
	t_stack	*a;
	t_stack	*tmp;
	int		index;

	index = 0;
	if (stack_name == 'a')
	{
		a = frame->a;
		tmp = frame->a->prev;
	}
	if (stack_name == 'b')
	{
		a = frame->b;
		tmp = frame->b->prev;
	}
	while (a->num != value && a->num != tmp->num)
	{
		index++;
		a = a->next;
	}
	return (index);
}

void	ft_put_index(int *ind, int i)
{
	(*ind) = i;
}

void	ft_index_stack(t_frame *frame)
{
	t_stack	*a;
	t_stack	*b;
	int		len_a;
	int		len_b;
	int		i;

	b = frame->b;
	a = frame->a;
	len_a = find_stack_len(frame, 'a');
	len_b = find_stack_len(frame, 'b');
	i = 0;
	while (len_a--)
	{
		ft_put_index(&a->index, i++);
		a = a->next;
	}
	i = 0;
	while (len_b--)
	{
		ft_put_index(&b->index, i++);
		b = b->next;
	}
}
