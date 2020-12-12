#include "c3d.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	int		i;
	char	*ptr;

	i = -1;
	if (!s)
		return (0);
	if (!(ptr = (char*)malloc(len + 1)))
		return (0);
	while (s[start] && i < (int)len - 1)
		ptr[++i] = s[start++];
	ptr[++i] = '\0';
	return (ptr);
}

char	*ft_strdup(char *s1)
{
	int		lensrc;
	char	*ptr;
	int		i;

	i = -1;
	lensrc = (int)ft_strlen(s1);
	if (!(ptr = malloc(lensrc + 1)))
		return (0);
	while (s1[++i])
		ptr[i] = s1[i];
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		l1;
	int		l2;
	int		i;
	int		j;
	char	*ret;

	i = 0;
	if (!s1)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(ret = malloc(l1 + l2 + 2)))
		return (0);
	if (s1 != NULL)
		while ((ret[i] = s1[i]))
			i++;
	j = 0;
	if (s2 != NULL)
		while ((ret[i++] = s2[j]))
			j++;
	free(s1);
	free(s2);
	ret[i] = '\0';
	return (ret);
}

ssize_t	nx(char *str)
{
	int		i;
	char	*s;

	s = (char *)str;
	i = 0;
	while (s[i] != '\n')
	{
		if (s[i])
			i++;
		else
			return (-1);
	}
	return (i);
}
