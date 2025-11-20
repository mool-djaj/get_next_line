/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaarich <akaarich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 20:05:05 by akaarich          #+#    #+#             */
/*   Updated: 2025/11/20 21:50:45 by akaarich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*join_and_free(char **s1, char *s2)
{
	char	*tmp;

	if (!s1 || !*s1 || !s2)
		return (NULL);
	tmp = ft_strjoin(*s1, s2);
	if (!tmp)
		return (free(*s1), *s1 = NULL, (NULL));
	free(*s1);
	*s1 = NULL;
	return (tmp);
}

char	*read_store(int fd, char **sta)
{
	ssize_t	byt_read;
	char	buff[BUFFER_SIZE + 1];

	if (!*sta)
		*sta = ft_strdup("");
	if (!*sta)
		return (free(*sta), *sta = NULL, (NULL));
	byt_read = 1;
	while (!ft_strchr(*sta, '\n') && byt_read > 0)
	{
		byt_read = read(fd, buff, BUFFER_SIZE);
		if (byt_read < 0)
			return (free(*sta), *sta = NULL, (NULL));
		buff[byt_read] = '\0';
		*sta = join_and_free(sta, buff);
	}
	return (*sta);
}

char	*extract_line(char *stash)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!stash || stash[0] == '\0')
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	tmp = ft_substr(stash, 0, i);
	return (tmp);
}

char	*sav_rest(char **sta)
{
	int		i ;
	char	*tmp;

	i = 0;
	while ((*sta)[i] && (*sta)[i] != '\n')
		i++;
	if ((*sta)[i] == '\0')
		return (free(*sta), *sta = NULL, (NULL));
	if ((*sta)[i] == '\n' && (*sta)[i + 1] == '\0')
		return (free(*sta), *sta = NULL, (NULL));
	tmp = ft_strdup(*sta + i + 1);
	free(*sta);
	*sta = NULL;
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*sta[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if (!read_store(fd, &sta[fd]))
		return (NULL);
	line = extract_line(sta[fd]);
	if (!line)
		return (free(sta[fd]), sta[fd] = NULL, (NULL));
	sta[fd] = sav_rest(&sta[fd]);
	return (line);
}
