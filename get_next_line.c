/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:34:15 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/01/11 14:40:14 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// BORRAR
#include <stdio.h>
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
void	ft_putnbr_fd(long n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
// -------------------------

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
	// write(1, "\nbuffer: ", 10);
	// write(1, buf, BUFFER_SIZE);

	// Count until endl or end of buffer
	endln_found = count_until_endl(buf, line, count);
	
	// write(1, "\ncount: ", 9);
	// ft_putnbr_fd(*count, 1);
	// write(1, "\n--- before ---\n", 17);
	// write(1, line, ft_strlen(line));
	
	// Join buffer to line
	subbuf = ft_substr(buf, 0, *count - ft_strlen(line));
	new_line = ft_strjoin(line, subbuf);
	
	// write(1, "\n--- after ---\n", 16);
	// write(1, new_line, ft_strlen(new_line));
	// write(1, "\n ---\n\n", 7);
	
	if (endln_found == 2)
		return (ft_bzero(buf, BUFFER_SIZE), free(line), free(subbuf), (new_line));

	if (BUFFER_SIZE <= ft_strlen(new_line))
	{
		ft_bzero(buf, BUFFER_SIZE);
		if (!endln_found)
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
