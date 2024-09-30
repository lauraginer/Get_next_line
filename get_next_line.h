/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:19:08 by lginer-m          #+#    #+#             */
/*   Updated: 2024/09/21 13:20:42 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

//-------------GET_NEXT_LINE.C----------------//
char	*get_next_line(int fd);
char	*gnl_strchr(const char *s, int c);
char	*gnl_read_txt(int fd, char *save);
char	*gnl_extract_line(char *save);
char	*gnl_the_rest(char *save);
//-------------GET_NEXT_LINE_UTILS.C----------------//
size_t	gnl_strlen(const char *str);
char	*gnl_strcpy(char *s1, const char *s2);
char	*gnl_strdup(const char *s);
size_t	gnl_strlcat(char *dst, const char *src, size_t dstsize);
char	*gnl_strjoin(char *str1, char *str2);

#endif