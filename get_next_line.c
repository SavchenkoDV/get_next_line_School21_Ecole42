/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buthor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 12:00:00 by buthor            #+#    #+#             */
/*   Updated: 2021/01/06 20:54:01 by buthor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	dst = NULL;
	if ((dst = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (i < len)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	char	*src;

	src = (char *)s;
	while (*src != '\0')
	{
		if (*src == (char)c)
			return (src);
		src++;
	}
	if (*src == (char)c && (char)c == '\0')
		return (src);
	return (NULL);
}

void	ft_strcpy(char *dst, const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_check(char **tail, char **line)
{
	char *pn;

	pn = NULL;
	if (*tail)
	{
		if ((pn = ft_strchr(*tail, '\n')))
		{
			*pn = '\0';
			*line = ft_strdup(*tail);
			ft_strcpy(*tail, ++pn);
		}
		else
		{
			*line = ft_strdup(*tail);
			ft_bzero(*tail, ft_strlen(*tail));
		}
	}
	else
		*line = ft_calloc(1, 1);
	return (pn);
}

int		get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static int	bwr;
	char		*pn;
	static char	*tail;

	if (!line || fd < 0 || BUFFER_SIZE <= 0 || (read(fd, 0, 0) < 0))
		return (-1);
	pn = ft_check(&tail, line);
	while (!pn && (bwr = read(fd, buff, BUFFER_SIZE)))
	{
		if (bwr < 0 || *line == NULL)
			break ;
		buff[bwr] = '\0';
		if ((norm25(&pn, buff, &tail, line)) == -1)
			return (-1);
	}
	if ((bwr == 0 && tail) || (*line == NULL && tail))
	{
		free(tail);
		tail = NULL;
	}
	if (*line == NULL || bwr < 0)
		return (-1);
	return ((bwr == 0 && (tail == NULL || ft_strlen(tail) == 0)) ? 0 : 1);
}
