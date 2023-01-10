/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:40:44 by fgomez-d          #+#    #+#             */
/*   Updated: 2023/01/10 21:28:47 by fgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (str == NULL)
		return (-1);
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

	newstr = (char *) malloc(ft_strlen(str) + 1 * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	ft_strlcpy(newstr, str, ft_strlen(str) + 1);
	return (newstr);
}