/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:40:44 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/01/13 14:44:25 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			i;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n && n != 0)
	{
		if (src >= dest)
		{
			ptr_dest[i] = ptr_src[i];
			i++;
		}
		else
		{
			ptr_dest[n - 1] = ptr_src[n - 1];
			n--;
		}
	}
	return (ptr_dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;

	if (s == NULL)
		return (NULL);
	if (start >= (unsigned int) BUFFER_SIZE)
		start = (unsigned int) BUFFER_SIZE;
	if (len > (unsigned int) BUFFER_SIZE - start)
		len = (unsigned int) BUFFER_SIZE - start;
	newstr = (char *) malloc((len + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	ft_strlcpy(newstr, s + start, len + 1);
	return (newstr);
}

char	*ft_strjoin(char const *s1, char *s2)
{
	char	*catstr;
	size_t	size;
	size_t	i;
	size_t	j;
	size_t	destlen;

	if (s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	catstr = (char *) malloc(size);
	if (catstr == NULL)
		return (free(s2), NULL);
	ft_strlcpy(catstr, s1, ft_strlen(s1) + 1);
	i = 0;
	destlen = ft_strlen(catstr);
	j = destlen;
	while (s2[i] != '\0' && i < size - destlen - 1)
	{
		catstr[j] = s2[i];
		j++;
		i++;
	}
	catstr[j] = '\0';
	free(s2);
	return (catstr);
}
