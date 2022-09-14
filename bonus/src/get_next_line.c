/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 17:52:15 by aechafii          #+#    #+#             */
/*   Updated: 2022/09/11 08:20:20 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

char	*ft_is_read(char *str, int fd)
{
	int		i;
	char	*buffer;

	i = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (i != 0 && ft_is_end_of_line(str) == 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == 0)
			break ;
		if (i < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = ft_is_read(buffer, fd);
	line = ft_is_the_line(buffer);
	buffer = ft_is_the_rest(buffer);
	return (line);
}
