/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 01:54:12 by hchaguer          #+#    #+#             */
/*   Updated: 2022/11/28 01:54:21 by hchaguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);
char	*ft_getline(char *str, int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_setline(char *str);
char	*ft_savenextline(char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
