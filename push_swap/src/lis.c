/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 05:01:09 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/17 03:56:37 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_lis(t_frame *frame)
{
	t_stack	*a;
	t_stack	*head;

	a = frame->a;
	head = a;
	while (1)
	{
		a->mark = 0;
		a->lis = 1;
		a = a->next;
		if (a == head)
			break ;
	}
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	find_lis(t_frame *frame)
{
	t_stack	*a;
	t_stack	*head;
	t_stack	*tmp;

	a = frame->a;
	head = a;
	ft_init_lis(frame);
	while (a->next != head)
	{
		tmp = a->next;
		while (tmp != head)
		{
			if (tmp->num > a->num)
				tmp->lis = ft_max(a->lis + 1, tmp->lis);
			tmp = tmp->next;
		}
		a = a->next;
	}
}

static int	locate_max_lis(t_frame *frame)
{
	t_stack	*a;
	t_stack	*tmp_lis;
	t_stack	*head;
	int		max_lis;

	max_lis = 0;
	a = frame->a;
	head = frame->a;
	tmp_lis = frame->a;
	while (1)
	{
		if (max_lis < a->lis)
		{
			max_lis = a->lis;
			tmp_lis = a;
		}
		a = a->next;
		if (a == head)
			break ;
	}
	return (max_lis);
}

void	mark_lis(t_frame *frame)
{
	int		max_lis;
	t_stack	*head;
	t_stack	*a;

	a = frame->a;
	head = frame->a;
	max_lis = locate_max_lis(frame);
	while (max_lis)
	{
		if (max_lis == a->lis)
		{
			max_lis--;
			a->mark = 1;
		}
		a = a->prev;
	}
}
