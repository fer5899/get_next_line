/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:34:47 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/01/16 19:34:13 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# define MAX_FD 10000

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
void	ft_strlcpy(char *dest, const char *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*recursive_get_ln(char *buf, char *ln, int fd, int subbuf_len);
int		count_until_endl(char *buf, int *ln_len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char *s2);
void	*ft_bzero(void *s, size_t n);
void	update_buf(char *buf, int subbuf_len, int endln_found);

#endif
