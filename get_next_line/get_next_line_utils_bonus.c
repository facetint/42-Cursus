/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:51:41 by facetint          #+#    #+#             */
/*   Updated: 2023/09/19 14:54:27 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*ret_val;
	int		i;

	if (!s)
		return (0);
	i = 0;
	ret_val = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ret_val)
		return (NULL);
	while (*s)
		ret_val[i++] = *s++;
	ret_val[i] = '\0';
	return (ret_val);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (*s1)
		new_str[i++] = *s1++;
	while (*s2)
		new_str[i++] = *s2++;
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	calc_len;

	calc_len = ft_strlen(s);
	if (!s || len <= 0)
		return (NULL);
	if (len > calc_len)
		len = calc_len;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = start;
	j = 0;
	while (i < calc_len && j < len)
	{
		res[j] = s[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

void	*ft_free(char **rem, int new_line)
{
	char	*line;

	if (!*rem)
		return (NULL);
	if (new_line == 0)
	{
		if (*rem)
		{
			free(*rem);
			*rem = NULL;
		}
		return (NULL);
	}
	else if (new_line == 1)
	{
		line = ft_strdup(*rem);
		if (*rem)
		{
			free(*rem);
			*rem = NULL;
		}
		return (line);
	}
	return (NULL);
}
