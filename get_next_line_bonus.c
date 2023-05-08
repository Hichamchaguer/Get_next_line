/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 01:37:15 by hchaguer          #+#    #+#             */
/*   Updated: 2022/11/28 01:55:14 by hchaguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_setlines(char *str);
char	*ft_savenextline(char *str);

char	*get_next_line(int fd)
{
	static char	*nextone[OPEN_MAX];
	char		s[BUFFER_SIZE + 1];
	char		*line;
	int			n;

	if ((fd < 0 || fd > 10240) || BUFFER_SIZE <= 0)
		return (0);
	n = 1;
	while (!(ft_strchr(nextone[fd], '\n')) && n != 0)
	{
		n = read(fd, s, BUFFER_SIZE);
		if (n == -1)
			return (NULL);
		s[n] = '\0';
		nextone[fd] = ft_strjoin(nextone[fd], s);
	}
	line = ft_setlines(nextone[fd]);
	nextone[fd] = ft_savenextline(nextone[fd]);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*ft_setlines(char *str)
{
	char	*s;
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	s = malloc(sizeof(char) * (i + 2));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return (s);
}

char	*ft_savenextline(char *str)
{
	char	*alloc;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	alloc = malloc((ft_strlen(str) - i) * sizeof(char));
	if (alloc == NULL)
		return (NULL);
	i++;
	j = 0;
	while (str[i] != '\0')
		alloc[j++] = str[i++];
	alloc[j] = '\0';
	free(str);
	return (alloc);
}
