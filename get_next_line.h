/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:34:47 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/01/11 13:58:04 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define MAX_FD 256 // execute "launchctl limit maxfiles" to check fd limit

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
int		ft_strlcpy(char *dest, const char *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *str);
char	*recursive_get_line(char *buf, char *line, int fd, int *count);
int		count_until_endl(char *buf, char *line, int *count);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_bzero(void *s, size_t n);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif