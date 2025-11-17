#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strdup(char *s);
int	ft_strlen(char *r);
char    *extract_line(char *stash);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char *read_store(int fd,char *sta);
char *sav_rest(char *sta);
size_t	ft_strlcpy(char *dst, char *src);
char *free_mlawi(char *sta);
char *join_and_free(char *s1, char *s2);

#endif