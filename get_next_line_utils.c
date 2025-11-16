/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaarich <akaarich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 22:15:29 by akaarich          #+#    #+#             */
/*   Updated: 2025/11/16 02:20:50 by akaarich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	unsigned int		i;
	unsigned int	leng;
	char			*d;

	leng = ft_strlen(s);
	i = 0;
	d = malloc((leng + 1));
	if (!d)
		return (NULL);
		
	
	while (i < leng)
	{
		d[i] = s[i];
		i++;
	}d[leng] = '\0';
	return (d);
}


int	ft_strlen(const char *r)
{
	int	i;

	i = 0;
	while (r[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i[2];
	char	*d;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i[0] = 0;
	i[1] = 0;
	d = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!d)
		return (NULL);
	d[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	while (i[0] < ft_strlen(s1))
		d[i[0]++] = s1[i[0]];
	while (i[1] < ft_strlen(s2))
		d[i[0] + i[1]++] = s2[i[1]];
	return (d);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*d;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	d = malloc(len + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (i < len)
	{
		d[i] = s[start + i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

size_t	ft_strlcpy(char *dst, const char *src)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}