/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:50:36 by facetint          #+#    #+#             */
/*   Updated: 2023/09/19 15:11:10 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

static char	*ft_copy(char *rem, char *buf)
{
	char	*res;

	res = 0;
	if (!rem && buf)
	{
		res = ft_strdup(buf);
		if (!res)
			return (NULL);
		return (res);
	}
	res = ft_strjoin(rem, buf);
	ft_free(&rem, 0);
	return (res);
}

static int	ft_checknl(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i] != '\0')
		if (s[i] == '\n')
			return (1);
	return (0);
}

static char	*ft_line_parser(char *rem)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	if (!rem)
		return (ft_free(&rem, 0));
	while (rem[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (ft_free(&line, 0));
	j = 0;
	while (j < i + 1)
	{
		line[j] = rem[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*ft_new_line(char *rem)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!rem)
		return (NULL);
	while (rem[i] != '\n')
		i++;
	if (rem[i + 1] == '\0')
		return (ft_free(&rem, 0));
	res = ft_substr(rem, i + 1, ft_strlen(rem));
	if (!res)
	{
		ft_free(&rem, 0);
		return (NULL);
	}
	ft_free(&rem, 0);
	return (res);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	long		rd_bytes;
	static char	*rem [NUM_OF_FD];
	char		*line;

	line = 0;
	rd_bytes = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free(&rem[fd], 0));
	while (rd_bytes > 0)
	{
		rd_bytes = read(fd, buf, BUFFER_SIZE);
		if ((rd_bytes <= 0 && !rem[fd]) || rd_bytes == -1)
			return (ft_free(&rem[fd], 0));
		buf[rd_bytes] = '\0';
		rem[fd] = ft_copy(rem[fd], buf);
		if (ft_checknl(rem[fd]))
		{
			line = ft_line_parser(rem[fd]);
			if (!line)
				return (ft_free(&rem[fd], 0));
			return (rem[fd] = ft_new_line(rem[fd]), line);
		}
	}
	return (ft_free(&rem[fd], 1));
}
