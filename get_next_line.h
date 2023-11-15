#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

char *get_next_line(int fd);
int ft_strchr(const char *s, char c);
size_t	ft_strlen(char *str);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strncat(char *dest, char *src, int nb);

#endif