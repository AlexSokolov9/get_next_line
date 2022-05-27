/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:27:58 by asokolov          #+#    #+#             */
/*   Updated: 2022/01/19 19:07:51 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*dest;
	int			i;

	i = 0;
	while (*s)
	{
		if (*s == '\0')
			return (NULL);
		if (*s == (char)c)
		{
			dest = s;
			return ((char *)dest);
		}
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

static int	ft_len(char const *s, size_t len, unsigned int start)
{
	size_t	i;

	i = 0;
	while (i < len && s[start])
	{
		i++;
		start++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	if (start >= (unsigned int)ft_strlen_c(s, '\0'))
	{
		dest = (char *)malloc(1);
		if (!dest)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	i = 0;
	dest = (char *)malloc(ft_len(s, len, start) * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	while (i < len && s[start])
	{
		dest[i] = s[start];
		start++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	res = (char *)malloc(ft_strlen_c(s1, '\0') + ft_strlen_c(s2, '\0')
			* sizeof(char) + 1);
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	free((char *)s1);
	return (res);
}

void	*ft_memmove(char *dst, char *src, int len)
{
	unsigned int	i;

	i = len;
	if (dst > src)
	{
		while (i--)
		{
			dst[i] = src[i];
		}
		return (dst);
	}
	else
	{
		i = 0;
		if (!dst && !src)
			return (NULL);
		while (i < (unsigned int)len)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}
