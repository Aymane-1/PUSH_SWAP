/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:46:10 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/14 11:59:25 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	atoi_push_swap(char *str)
{
	long	num;
	int		i;
	int		len;
	int		sign;

	num = 0;
	i = 0;
	len = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f')
		i++;
	if (str[i] == '-')
		sign = -1;
	else
		sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
		len++;
	}
	return (num * sign);
}

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
			while ((*(str + j) == '-' || *(str + j) == '+'
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
			else if (*str == '-' && ft_isdigit(*(str + 1)))
				str++;
			else if (*str == '+' && ft_isdigit(*(str + 1)))
				str++;
			else
				push_swap_error(frame);
		}
		str = frame->argv[++i];
	}
}

void	fill_stack_a(t_frame *frame)
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
