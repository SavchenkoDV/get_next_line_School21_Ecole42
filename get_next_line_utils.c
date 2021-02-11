/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buthor <buthor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 20:53:20 by buthor            #+#    #+#             */
/*   Updated: 2021/01/06 20:54:01 by buthor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void *p;

	p = NULL;
	if ((p = malloc(sizeof(char) * (count * size))) == NULL)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str1;
	char	*str2;
	char	*dst;
	size_t	i;
	size_t	size_dst;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	dst = NULL;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size_dst = ft_strlen(s1) + ft_strlen(s2);
	if ((dst = malloc(sizeof(char) * (size_dst + 1))) == NULL)
		return (NULL);
	while (*str1 != '\0')
		dst[i++] = *str1++;
	while (*str2 != '\0')
		dst[i++] = *str2++;
	dst[i] = '\0';
	return (dst);
}

int		norm25(char **pn, char *buff, char **tail, char **line)
{
	char	*tmp;

	tmp = NULL;
	if ((*pn = ft_strchr(buff, '\n')))
	{
		**pn = '\0';
		tmp = *tail;
		*tail = ft_strdup(*pn + 1);
		free(tmp);
		if (*tail == NULL)
			return (-1);
	}
	tmp = *line;
	*line = ft_strjoin(*line, buff);
	free(tmp);
	return (1);
}
