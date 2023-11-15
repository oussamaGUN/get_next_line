#include "get_next_line.h"

char *ft_line(char *buffer, int fd, char *line)
{
    int byts;
    static char saved[OPEN_MAX];


    byts = read(fd, buffer, BUFFER_SIZE);
    if (byts == 0)
    {
        free(buffer);
        return NULL;
    }
    ft_strncat(saved, buffer, byts);
    while (ft_strchr(saved, '\n') == 0 && byts > 0)
    {
        byts = read(fd, buffer, BUFFER_SIZE);
        if (byts <= 0)
        {
            free(buffer);
            return NULL;
        }
        ft_strncat(saved, buffer, byts);
    }
    free(buffer);
    int i = 0;
    line = malloc(sizeof(char) * (ft_strlen(saved) + 1));
    if (!line)
        return NULL;
    while (saved[i] != '\n' && saved[i])
    {
        line[i] = saved[i];
        i++;
    }
    if (saved[i] != '\0')
    {
        line[i] = '\n';
        line[i + 1] = '\0';
    }
    else
        line[i] = '\0';
    ft_memmove(saved, saved + i + 1, ft_strlen(saved) - i);
    
    return line;
}

char *get_next_line(int fd)
{
    char *buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return NULL;
    char *line = NULL;
    if (fd <= -1 || fd == STDOUT_FILENO || fd == STDERR_FILENO || fd >= OPEN_MAX
		|| read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0)
    {
        free(buffer);
        return (NULL);
    }
    line = ft_line(buffer, fd, line);
    if (!line)
        return NULL;
    return line;
}


/*int main(void)
{
    int fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
    if (!(line = (char *)malloc(sizeof(char*) * 10000)))
        return (0);

    line = get_next_line(fd);
    int i = 0;
    while (i < 4)
    {
        printf("%s\n", line);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    free(line);
    return(0);
}*/
