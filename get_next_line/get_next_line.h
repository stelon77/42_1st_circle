/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 10:53:34 by lcoiffie          #+#    #+#             */
/*   Updated: 2020/01/31 10:23:11 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define MAX_FD 1025
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		get_next_line(int fd, char **line);
int		gnl_strchr(char **rest, char **line);
int		gnl_read_file(char *temp, char **rest, char **line, int fd);
int		gnl_strlen(const char *s);
char	*gnl_strdup(const char *s1);
char	*gnl_strjoin(char *s1, char *s2);
int		gnl_free_mem(char *s1, char *s2, int value);

#endif
