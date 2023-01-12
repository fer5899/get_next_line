/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:34:15 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/01/12 11:11:35 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	count_until_endl(char *buf, char *line, int *count)
{
	while (*count - ft_strlen(line) < BUFFER_SIZE)
	{
		if (buf[*count - ft_strlen(line)] == '\n')
		{
			*count += 1;
			return (1);
		}
		if (buf[*count - ft_strlen(line)] == '\0')
		{
			*count += 1;
			return (2);
		}
		*count += 1;
	}
	return (0);
}

char	*recursive_get_line(char *buf, char *line, int fd, int *count)
{
	int			endln_found;
	char		*new_line;
	char		*subbuf;

	if (buf[0] == '\0')
		if (read(fd, buf, BUFFER_SIZE) < 1 && line[0] == '\0')
			return (free(line), NULL);
	if (buf[0] == '\0')
		return (line);
	endln_found = count_until_endl(buf, line, count);
	subbuf = ft_substr(buf, 0, *count - ft_strlen(line));
	new_line = ft_strjoin(line, subbuf);
	if (endln_found == 2)
		return (ft_bzero(buf, BUFFER_SIZE), free(line), free(subbuf), (new_line));
	if (BUFFER_SIZE <= ft_strlen(new_line) && !endln_found)
	{
		ft_bzero(buf, BUFFER_SIZE);
		new_line = recursive_get_line(buf, new_line, fd, count);
		free(line);
		free(subbuf);
	}
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	char		*line;
	int			count;

	if (BUFFER_SIZE < 1)
		return (NULL);
	line = malloc(1);
	ft_bzero(line, 1);
	count = 0;
	line = recursive_get_line(buf, line, fd, &count);
	if (BUFFER_SIZE >= ft_strlen(line))
	{
		ft_memmove(buf, buf + count, BUFFER_SIZE - count);
		buf[BUFFER_SIZE - count] = '\0';
	}
	else
		ft_bzero(buf, BUFFER_SIZE);
	return (line);
}
