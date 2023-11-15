#include "get_next_line.h"


size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int ft_strchr(const char *s, char c)
{
    int i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return 1;
		i++;
	}
	return (0);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_cast;
	unsigned char	*s;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	s = (unsigned char *)src;
	dest_cast = (unsigned char *)dest;
	i = 0;
	if (dest_cast <= s)
	{
		while (i < n)
		{
			dest_cast[i] = s[i];
			i++;
		}
	}
	else
		while (n--)
			dest_cast[n] = s[n];
	return (dest_cast);
}

char	*ft_strncat(char *dest, char *src, int nb)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}