/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:18:35 by lginer-m          #+#    #+#             */
/*   Updated: 2024/09/21 13:19:18 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strcpy(char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*gnl_strdup(const char *s)
{
	size_t		len;
	char		*dest;

	if (!s)
		return (NULL);
	len = gnl_strlen(s);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	gnl_strcpy(dest, s);
	return (dest);
}

size_t	gnl_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	dst_len = gnl_strlen(dst);
	src_len = gnl_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = dst_len;
	j = 0;
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}

char	*gnl_strjoin(char *str1, char *str2)
{
	char	*result;
	size_t	len;
	size_t	len2;

	if (!str1 && !str2)
		return (NULL);
	if (!str1)
		return (gnl_strdup(str2));
	if (!str2)
		return (gnl_strdup(str1));
	len = gnl_strlen(str1);
	len2 = gnl_strlen(str2);
	result = (char *)malloc(sizeof(char) * (len + len2 + 1));
	if (!result)
		return (NULL);
	gnl_strcpy(result, str1);
	gnl_strlcat(result, str2, len + len2 + 1);
	free(str1);
	return (result);
}
