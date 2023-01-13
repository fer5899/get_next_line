/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:34:15 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/01/13 12:08:35 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// BORRAR
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}
void	ft_putstrn_fd(char *s, int len, int fd)
{
	int	i;

	i = 0;
	if (len < 0)
		len = 0;
	while (i < len)
	{
		write(fd, &s[i], 1);
		i++;
	}
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
// ---------------------------

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
