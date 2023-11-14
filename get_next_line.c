#include "get_next_line.h"
#include <string.h>

char *ft_line(char *buffer, int fd, char *line)
{
    int byts;
    
    static char saved[OPEN_MAX];
    byts = read(fd, buffer, BUFFER_SIZE);
    strncat(saved, buffer, byts);
    while (ft_strchr(saved, '\n') == 0 && byts > 0)
    {
        byts = read(fd, buffer, BUFFER_SIZE);
        strncat(saved, buffer, byts);
    }
    int i = 0;
    line = malloc(sizeof(char) * (ft_strlen(saved) + 1));
    if (!line)
        return NULL;
    while (saved[i] != '\n' && saved[i])
    {
        line[i] = saved[i];
        i++;
    }
    line[i] = '\n';
    line[i + 1] = '\0';
    memmove(saved, saved + i + 1, strlen(saved) - i);
    
    return line;
}

char *get_next_line(int fd)
{
    char buffer[BUFFER_SIZE];
    char *line = NULL;
    if (fd < 0)
        return (NULL);
    line = ft_line(buffer, fd, line);
    return line;
}
int main()
{
    int fd = open("file.txt", O_RDWR);
 
    char *l = get_next_line(fd); 
    printf("%s", l);

    // char *s = get_next_line(fd); 
    // printf("%s", s);
    // free(s);
    // char *d = get_next_line(fd); 
    // printf("%s", d);

    // char *q = get_next_line(fd); 
    // printf("%s", q);

    close(fd);
}
