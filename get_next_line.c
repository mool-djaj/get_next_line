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

char *read_store(int fd, char *sta)
{
    ssize_t byt_read;
    char    buff[BUFFER_SIZE + 1];

    if (!sta)
        sta = ft_strdup("");
    if (!sta)
        return NULL;
    byt_read = 1;
    while (!ft_strchr(sta, '\n') && byt_read > 0)
    {
        byt_read = read(fd, buff, BUFFER_SIZE);
        if (byt_read < 0)
        {
            free(sta);
            return NULL;
        }
        buff[byt_read] = '\0';
        sta = ft_strjoin(sta, buff);
        if (!sta)
            return NULL;
    }
    return sta;
}

char *extract_line(char *stash)
{
    size_t i;

	i = 0;
    if (!stash || stash[0] == '\0')
        return NULL;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        i++;
    return ft_substr(stash, 0, i);
}

char *sav_rest(char *sta)
{
    size_t i;
    char *tmp;

	i = 0;
    while (sta[i] && sta[i] != '\n')
        i++;
    if (!sta[i])
    {
        free(sta);
        return NULL;
    }
    tmp = ft_strdup(sta + i + 1);
    free(sta);
    return tmp;
}

char *get_next_line(int fd)
{
    static char *sta;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        free(sta);
        sta = NULL;
        return NULL;
    }
    sta = read_store(fd, sta);
    if (!sta)
    {
        sta = NULL;
        return NULL;
    }
    line = extract_line(sta);
    sta = sav_rest(sta);
    return line;
}
int main(void)
{
    int fd = open("txt.txt", O_RDONLY);
    char *buff;

    if (fd < 0)
        return (1);

    while ((buff = get_next_line(fd)) != NULL)
    {
        printf("%s", buff);
        free(buff);
    }

    close(fd);
    return (0);
}
