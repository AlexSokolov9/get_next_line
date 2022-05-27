/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asokolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:47:21 by asokolov          #+#    #+#             */
/*   Updated: 2022/01/19 18:57:42 by asokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_c(const char *buff, char c)
{
	int	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == c)
			return (i);
		i++;
	}
	return (i);
}

void	ft_remainder(char *buff)
{
	int	size;

	size = ft_strlen_c(buff, '\0') - (ft_strlen_c(buff, '\n') + 1);
	if (size > 0)
	{
		ft_memmove(buff, &buff[ft_strlen_c(buff, '\n') + 1], size);
		buff[size] = '\0';
	}
	else
		buff[0] = '\0';
}

char	*ft_line(char *buff, char *line)
{
	char	*tmp;

	tmp = ft_substr(buff, 0, ft_strlen_c(buff, '\n') + 1);
	line = ft_strjoin(line, tmp);
	if (line == NULL)
	{
		free(tmp);
		free(line);
		return (NULL);
	}
	free(tmp);
	return (line);
}

char	*ft_reading(int fd, char *buff, char *line, ssize_t r)
{
	while (ft_strchr(line, '\n') == NULL)
	{
		if (buff[0] == '\0')
		{
			r = read(fd, buff, BUFFER_SIZE);
			if (r <= 0)
			{
				if (line[0] == '\0' || r < 0)
				{
					free(line);
					return (NULL);
				}
				else
					return (line);
			}
			buff[r] = '\0';
		}
		if (ft_strchr(buff, '\n') == NULL)
			line = ft_strjoin(line, buff);
		else
			line = ft_line(buff, line);
		ft_remainder(buff);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1] = {{0}};
	char		*line;
	char		*buff;
	ssize_t		r;

	if (fd < 0)
		return (NULL);
	buff = &buffer[fd][0];
	line = (char *)malloc(sizeof (char) * 1);
	if (!line)
		return (NULL);
	r = 0;
	line[0] = '\0';
	line = ft_reading(fd, buff, line, r);
	return (line);
}
