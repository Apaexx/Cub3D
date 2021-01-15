#include "c3d.h"

int		check_map(t_map *data, int j)
{
	int		i;
	int		k;
	int		x;

	k = -1;
	x = 0;
	while (++k < j)
	{
		i = -1;
		while (data->jmap[k][++i])
		{
			if (((ft_strchr("WSNE102", data->jmap[k][i]) < 0) &&
			(data->jmap[k][i] > ' ')) ||
			((ft_strchr("WSNE", data->jmap[k][i]) > -1) && x++))
				return (0);
			if ((ft_strchr("WSNE02", data->jmap[k][i]) > -1))
				if (!(k && i && (k < j) && (i < ft_strlen(data->jmap[k - 1])
				&& (i < ft_strlen(data->jmap[k + 1]) && (i <
				ft_strlen(data->jmap[k])) && (data->jmap[k][i + 1] > ' ') &&
				(data->jmap[k][i - 1] > ' ') && (data->jmap[k + 1][i] > ' ')
				&& (data->jmap[k - 1][i] > ' ')))))
					return (0);
		}
	}
	return (x);
}

int		check_list(t_map *data)
{
	if (!(data->res[0] * data->res[1] * data->ymap) || !(data->north &&
	data->east && data->south && data->west && data->sprite) ||
	!((data->c[3] + 1) * (data->f[3] + 1)))
		return (0);
	return (1);
}
