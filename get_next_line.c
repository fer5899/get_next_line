/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:34:15 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/01/10 21:38:06 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *buf, char *line, char *aux, int count)
{
	free(line);
	line = malloc(ft_strlen(aux) + count + 1);
	ft_strlcpy(line, buf, ft_strlen(aux) + count + 1);
	free(aux);
	ft_memmove(buf, buf + count, BUFFER_SIZE - count);
	buf[BUFFER_SIZE - count] = '\0';
	return (line);
}

int	count_until_endl(char *buf, int *count)
{
	while (*count < BUFFER_SIZE)
	{
		if (buf[*count] == '\n' || buf[*count] == '\0')
			return (1);
		count++;
	}
	return (0);
}

char	*recursive_get_line(char *buf, char *line, char *aux, int fd)
{
	int			count;
	int			endln_found;

	if (buf[0] == '\0')
		if (read(fd, buf, BUFFER_SIZE) < 1)
			return (free(line), free(aux), NULL);
	count = 0;
	endln_found = count_until_endl(buf, &count);
	line = extract_line(buf, line, aux, count);
	if (!endln_found)
	{
		aux = ft_strdup(line);
		recursive_get_line(buf, line, aux, fd);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	char		*line;
	char		*aux;

	if (BUFFER_SIZE < 1)
		return (NULL);
	line = malloc(1);
	aux = malloc(1);
	return (recursive_get_line(buf, line, aux, fd));
}
