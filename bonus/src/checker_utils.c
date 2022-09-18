/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 06:22:53 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/16 22:54:16 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	sorted(t_frame *frame)
{
	t_stack		*tmp;

	if (!frame->a || frame->b)
		return (0);
	tmp = frame->a;
	while (tmp->next != frame->a)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	compare_results(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	if (s1[i] == s2[i])
		return (1);
	else
		return (0);
}

static	void	execute_operations(t_frame *frame, char *output_ins)
{
	if (compare_results("pa\n", output_ins))
		do_pa(frame, 0);
	else if (compare_results("pb\n", output_ins))
		do_pb(frame, 0);
	else if (compare_results("sa\n", output_ins))
		do_sa(frame, 0);
	else if (compare_results("sb\n", output_ins))
		do_sb(frame, 0);
	else if (compare_results("ss\n", output_ins))
		do_ss(frame, 0);
	else if (compare_results("ra\n", output_ins))
		do_ra(frame, 0);
	else if (compare_results("rb\n", output_ins))
		do_rb(frame, 0);
	else if (compare_results("rr\n", output_ins))
		do_rr(frame, 0);
	else if (compare_results("rra\n", output_ins))
		do_rra(frame, 0);
	else if (compare_results("rrb\n", output_ins))
		do_rrb(frame, 0);
	else if (compare_results("rrr\n", output_ins))
		do_rrr(frame, 0);
	else
		push_swap_error(frame);
}

void	read_instructions(t_frame *frame)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		execute_operations(frame, line);
		line = get_next_line(0);
	}
	if (sorted(frame) && !(frame->b))
		write(1, "\033[1;32mOK\n", 11);
	else
		write(1, "\033[1;31mKO\n", 11);
	free(line);
}
