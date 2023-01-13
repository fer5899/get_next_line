/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:34:15 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/01/13 12:22:11 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	count_until_endl(char *buf, int *line_len)
{
	while (*line_len < BUFFER_SIZE)
	{
		if (buf[*line_len] == '\n')
		{
			*line_len += 1;
			return (1);
		}
		if (buf[*line_len] == '\0')
			return (0);
		*line_len += 1;
	}
	return (0);
}

char	*recursive_get_line(char *buf, char *line, int fd)
{
	int			endln_found;
	int			subbuf_len;
	char		*new_line;
	char		*subbuf;

	if (buf[0] == '\0')
		if (read(fd, buf, BUFFER_SIZE) < 1)
		{
			if (line[0] == '\0')
				return (ft_bzero(buf, BUFFER_SIZE), free(line), NULL);
			else
				return (line);
		}
	subbuf_len = 0;
	endln_found = count_until_endl(buf, &subbuf_len);
	subbuf = ft_substr(buf, 0, subbuf_len);
	new_line = ft_strjoin(line, subbuf);
	if (endln_found == 0)
	{
		ft_bzero(buf, BUFFER_SIZE);
		return (free(line), free(subbuf), recursive_get_line(buf, new_line, fd));
	}
	else
	{
		if (endln_found == 2)
			ft_bzero(buf, BUFFER_SIZE);
		else
		{
			ft_memmove(buf, buf + subbuf_len, BUFFER_SIZE - subbuf_len);
			ft_bzero(buf + (BUFFER_SIZE - subbuf_len), subbuf_len);
		}
	}
	free(line);
	free(subbuf);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	char		*line;

	if (BUFFER_SIZE < 1)
		return (NULL);
	line = malloc(1);
	ft_bzero(line, 1);
	line = recursive_get_line(buf, line, fd);
	return (line);
}
