#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

char *get_next_line(int fd);
size_t	ft_strlen(char *str);
int ft_strchr(const char *s, char c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
typedef struct s_list{
    int index;
}t_list;

#endif