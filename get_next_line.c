/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:34:15 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/01/13 12:54:00 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	count_until_endl(char *buf, int *ln_len)
{
	while (*ln_len < BUFFER_SIZE)
	{
		if (buf[*ln_len] == '\n')
		{
			*ln_len += 1;
			return (1);
		}
		if (buf[*ln_len] == '\0')
			return (0);
		*ln_len += 1;
	}
	return (0);
}

void	update_buf(char *buf, int subbuf_len, int endln_found)
{
	if (endln_found == 2)
			subbuf_len = BUFFER_SIZE;
	ft_memmove(buf, buf + subbuf_len, BUFFER_SIZE - subbuf_len);
	ft_bzero(buf + (BUFFER_SIZE - subbuf_len), subbuf_len);
}

char	*recursive_get_ln(char *buf, char *ln, int fd, int subbuf_len)
{
	int			endln_found;
	char		*new_ln;

	if (buf[0] == '\0')
	{
		if (read(fd, buf, BUFFER_SIZE) < 1)
		{
			if (ln[0] == '\0')
				return (ft_bzero(buf, BUFFER_SIZE), free(ln), NULL);
			else
				return (ln);
		}
	}
	endln_found = count_until_endl(buf, &subbuf_len);
	new_ln = ft_strjoin(ln, ft_substr(buf, 0, subbuf_len));
	if (endln_found == 0)
		return (ft_bzero(buf, BUFFER_SIZE), free(ln), \
				recursive_get_ln(buf, new_ln, fd, 0));
	else
		update_buf(buf, subbuf_len, endln_found);
	free(ln);
	return (new_ln);
}


char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	char		*line;

	if (BUFFER_SIZE < 1)
		return (NULL);
	line = malloc(1);
	ft_bzero(line, 1);
	line = recursive_get_ln(buf, line, fd, 0);
	return (line);
}
