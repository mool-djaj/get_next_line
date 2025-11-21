#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char *ft_tup(char *s)
{
    int i = 0;
    while (s[i])
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - 32;
        i++;
    }
    return s;
}
int main()
{
	int i = 0;
    int fd = open("txt.txt", O_RDWR);
	int fd1 = open("txt2.txt", O_RDWR);
    if (fd < 0 || fd1 < 0)
    {
        printf("open failed");
        return 1;
    }

    char *line;
	char *line1;

    while (i < 20)
    {
		
		line = get_next_line(fd);
        if (ft_strchr(line, '-'))
        {
			line = get_next_line(fd);
			line = ft_tup(line);
            write(fd, line, ft_strlen(line));
        }
		line1 = get_next_line(fd1);
		if (ft_strchr(line1, '-'))
        {
			line1 = get_next_line(fd1);
			line1 = ft_tup(line1);
            write(fd1, line1, ft_strlen(line1));
        }
		i++;
    }

	close (fd);
	close (fd1);

}

