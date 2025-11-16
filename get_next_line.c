/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaarich <akaarich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 22:15:20 by akaarich          #+#    #+#             */
/*   Updated: 2025/11/16 02:36:34 by akaarich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_store(int fd,char *sta)
{
	ssize_t byt_itread;
	char buff[BUFFER_SIZE + 1];

	if (!sta)
		sta = ft_strdup("");

	byt_itread = read(fd,buff,BUFFER_SIZE);

	if (byt_itread <= 0)
	{
		return NULL;
	}
	sta = ft_strjoin(sta,buff);
	return (sta);
}
char    *extract_line(char *stash)
{
    size_t  i;
    char    *line;

    if (!stash || stash[0] == '\0')
        return (NULL);
    i = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        line = ft_substr(stash, 0, i + 1);
    else
        line = ft_substr(stash, 0, i);

    return (line);
}


char	*sav_rest(char *sta)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (sta[i] && sta[i] != '\n')
		i++;
	if (!sta[i])
	{
		free(sta);
		return (NULL);
	}
	i++;
	tmp = malloc(ft_strlen(sta + i) + 1);
	if (!tmp)
		return (NULL);
	j = 0;
	while (sta[i])
		tmp[j++] = sta[i++];
	tmp[j] = '\0';
	free(sta);
	return (tmp);
}


char *get_next_line(int fd)
{
	static char *sta;
	char *sta2;
	sta = read_store(fd,sta);
	sta2 = extract_line(sta);
	sta = sav_rest(sta);
	return sta2;

}



int main()
{
	int fd = open("txt.txt", O_RDONLY);
	char *line;

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}
