/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 06:09:29 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/14 00:42:53 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_duplicates(t_frame *frame)
{
	t_stack		*slow;
	t_stack		*fast;

	slow = frame->a;
	while (slow != frame->a->prev)
	{
		fast = slow->next;
		while (fast != frame->a)
		{
			if (slow->num == fast->num)
				push_swap_error(frame);
			fast = fast->next;
		}
		slow = slow->next;
	}
}

static void	complete_filling(t_frame *frame, char *str, int i, int j)
{
	long int	test_int_size;

	while (str != NULL)
	{
		while (*str != '\0')
		{
			j = 0;
			while (*str && *str == ' ')
				str++;
			while (*(str + j) && (*(str + j) == '-' || *(str + j) == '+'
					|| ft_isdigit(*(str + j))))
				j++;
			if (!*str)
				break ;
			test_int_size = atoi_push_swap(str);
			if (test_int_size > 2147483647 || test_int_size < -2147483648)
				push_swap_error(frame);
			stack_add_end(frame, 'a', test_int_size);
			str += j;
		}
		str = frame->argv[++i];
	}
	if (!frame->a)
		push_swap_error(frame);
}

static void	error_parser(t_frame *frame)
{
	char	*str;
	int		i;

	i = 1;
	str = frame->argv[i];
	while (str)
	{
		while (*str != '\0')
		{
			if (*str == ' ' || ft_isdigit(*str))
				str++;
			else if (*str == '-' && ft_isdigit(*(str + 1))
				&& (str == frame->argv[i] || *(str - 1) == ' '))
				str++;
			else if (*str == '+' && ft_isdigit(*(str + 1))
				&& (str == frame->argv[i] || *(str - 1) == ' '))
				str++;
			else
				push_swap_error(frame);
		}
		str = frame->argv[++i];
	}
}

void	fill_stack_a_c(t_frame *frame)
{
	char	*str;
	int		i;
	int		j;

	i = 1;
	j = 0;
	str = frame->argv[i];
	error_parser(frame);
	complete_filling(frame, str, i, j);
	check_duplicates(frame);
}

int	main(int argc, char **argv)
{
	t_frame		*frame;

	frame = NULL;
	if (argc < 2)
		return (1);
	frame = create_frame(frame, argv);
	fill_stack_a(frame);
	read_instructions(frame);
	push_swap_free(frame);
	return (0);
}
