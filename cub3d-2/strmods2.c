#include "c3d.h"

int		ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && (i + 1 < n))
		i++;
	return (s1[i] - s2[i]);
}

int		ft_strchr(char *str, char c)
{
	int		i;
	char	*s;

	s = (char *)str;
	i = 0;
	while (s[i] != c)
	{
		if (s[i])
			i++;
		else
			return (-1);
	}
	return (i);
}

int		ft_atoi(char *str)
{
	int	a;
	int i;

	a = 0;
	i = 0;
	if (!ft_isdigit(str[i]))
		return (-1);
	while (ft_isdigit(str[i]))
	{
		a = a * 10 + (str[i++] - '0');
	}
	return (a);
}

int		ft_isdigit(int n)
{
	if ((n >= '0' && n <= '9'))
		return (1);
	return (0);
}

void	sinit(t_map *data)
{
	data->fd = 0;
	data->gg = 1;
	data->res[0] = 0;
	data->res[1] = 0;
	data->f[0] = -1;
	data->f[1] = -1;
	data->f[2] = -1;
	data->f[3] = -1;
	data->c[0] = -1;
	data->c[1] = -1;
	data->c[2] = -1;
	data->c[3] = -1;
	data->ymap = 0;
	data->east = 0;
	data->north = 0;
	data->south = 0;
	data->west = 0;
	data->sprite = 0;
}
