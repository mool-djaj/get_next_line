/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaarich <akaarich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 20:05:05 by akaarich          #+#    #+#             */
/*   Updated: 2025/11/19 20:23:31 by akaarich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *join_and_free(char **s1, char *s2)
{
	if(!s1 || !*s1 || !s2)
		return NULL;
    char *tmp = ft_strjoin(*s1, s2);
    if (!tmp)
    {
        free(*s1);
        *s1 = NULL;
        return NULL;
    }
    free(*s1);
    *s1 = NULL;
    return tmp;
}

char *read_store(int fd, char **sta)
{
    ssize_t byt_read;
    char    buff[BUFFER_SIZE + 1];

    if (!*sta)
        *sta = ft_strdup("");
    if (!*sta)
		{
			free(*sta);
			*sta = NULL ;        	
			return NULL;
		}
    byt_read = 1;
    while (!ft_strchr(*sta, '\n') && byt_read > 0)
    {
        byt_read = read(fd, buff, BUFFER_SIZE);
        if (byt_read < 0)
        {
            free(*sta);
            *sta = NULL;
            return NULL;
        }
        buff[byt_read] = '\0';
        *sta = join_and_free(sta, buff);
	}
    return *sta;
}

char *extract_line(char *stash)
{
	char *tmp;
    size_t i = 0;

    if (!stash || stash[0] == '\0')
        return NULL;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        i++;
    tmp = ft_substr(stash, 0, i);
	return tmp;
}

char *sav_rest(char **sta)
{
    int   i = 0;
    char *tmp;

    while ((*sta)[i] && (*sta)[i] != '\n')
        i++;
	if ((*sta)[i] == '\0')
		{
    		free(*sta);
    		*sta = NULL;
    		return NULL;
		}
	if ((*sta)[i] == '\n' && (*sta)[i + 1] == '\0')
		{
    		free(*sta);
    		*sta = NULL;
    		return NULL;
		}
    tmp = ft_strdup(*sta + i + 1);
    free(*sta);
    *sta = NULL;
    return tmp;
}

char *get_next_line(int fd)
{
    static char *sta[OPEN_MAX];
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
        return NULL;

    if (!read_store(fd, &sta[fd]))
        return NULL;

    line = extract_line(sta[fd]);
	if(!line)
		{	
			free(sta[fd]);
			sta[fd] = NULL;
			return NULL;
		}
    sta[fd] = sav_rest(&sta[fd]);
		

    return line;
}



// int main(void)
// {
//     int fd = open("txt.txt", O_RDONLY);
//     char *buff;

//     if (fd < 0)
//         return (1);

//     while ((buff = get_next_line(fd)) != NULL)
//     {
// 		if (ft_strchr(buff , ))
// 		{
// 			/* code */
// 		}
		
//         printf("%s", buff);
//         free(buff);
//     }

//     close(fd);
//     return (0);
// }