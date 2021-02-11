/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buthor <buthor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:51:59 by buthor            #+#    #+#             */
/*   Updated: 2021/01/06 21:03:04 by buthor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		norm25(char **pn, char *buff, char **tail, char **line);
char	*ft_strdup(const char *s1);
void	ft_strcpy(char *dst, const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_check(char **tail, char **line);
int		get_next_line(int fd, char **line);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(const char *s1, const char *s2);

#endif
