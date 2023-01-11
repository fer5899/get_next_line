/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:40:44 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/01/11 12:52:07 by fgomez-d         ###   ########.fr       */
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

int	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	int		srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (srclen);
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

char	*ft_strdup(const char *str)
{
	char	*newstr;

	newstr = (char *) malloc((ft_strlen(str) + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	ft_strlcpy(newstr, str, ft_strlen(str) + 1);
	return (newstr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;

	if (s == NULL)
		return (NULL);
	if (start >= (unsigned int) ft_strlen(s))
		start = (unsigned int) ft_strlen(s);
	if (len > (unsigned int) ft_strlen(s) - start)
		len = (unsigned int) ft_strlen(s) - start;
	newstr = (char *) malloc((len + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	ft_strlcpy(newstr, s + start, len + 1);
	return (newstr);
}

int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		destlen;

	i = 0;
	destlen = ft_strlen(dest);
	if (size > destlen)
	{
		while (*dest != '\0')
			dest++;
		while (src[i] != '\0' && i < size - destlen - 1)
			*(dest++) = src[i++];
		*dest = '\0';
	}
	if (size < destlen)
		return ((int) size + ft_strlen(src));
	return ((int) destlen + ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*catstr;
	int		s1len;

	s1len = ft_strlen(s1);
	catstr = (char *) malloc((s1len + ft_strlen(s2) + 1) * sizeof(char));
	if (catstr == NULL)
		return (NULL);
	ft_strlcpy(catstr, s1, s1len + 1);
	ft_strlcat(catstr, s2, s1len + ft_strlen(s2) + 1);
	return (catstr);
}

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)0;
		i++;
	}
	return (ptr);
}