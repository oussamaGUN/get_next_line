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
char	*ft_strdup(const char *s)
{
	char		*dst;
	size_t		size;
	int			i;

	size = ft_strlen((char *)s);
	dst = (char *)malloc(sizeof(char) * (size + 1));
	if (!dst || !s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*s;
	size_t		len;
	size_t		len1;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen((char *)s2);
	len = ft_strlen((char *)s1);
	s = (char *)malloc(sizeof(char) * (len + len1 + 1));
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (j < len)
		s[i++] = s1[j++];
	j = 0;
	while (j < len1)
		s[i++] = s2[j++];
	s[i] = '\0';
	return (s);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen((char *)s))
		return (ft_strdup(""));
	if (len > ft_strlen((char *)s))
		len = ft_strlen((char *)s);
	if (len > ft_strlen((char *)s) - start)
		len = ft_strlen((char *)s) - start;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (s[start] && i < len && start < ft_strlen((char *)s))
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}