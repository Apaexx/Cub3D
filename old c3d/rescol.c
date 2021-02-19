#include "c3d.h"

int		win_res(t_map *data, char *restr, int j)
{
	int i;

	i = 0;
	while (restr && restr[i])
	{
		if (restr[i] > ' ')
		{
			if (((data->res[j] = ft_atoi(&restr[i], ' ')) > 0) && j < 2)
			{
				if (j)
					return (1);
				while (ft_isdigit(restr[i]))
					i++;
				return (win_res(data, &restr[i], ++j));
			}
			else
				return (-1);
		}
		i++;
	}
	return (-1);
}

int		flooor(t_map *data, char *colstr, int j)
{
	int i;

	i = 0;
	while ((colstr && colstr[i]))
	{
		if ((colstr[i++] > ' ' && i--))
		{
			if (colstr[i] == ',')
				i++;
			if (((data->f[j] = ft_atoi(&colstr[i], ',')) >= 0) &&
			(data->f[j] < 256))
			{
				while (ft_isdigit(colstr[i]))
					colstr++;
				return (flooor(data, &colstr[i], ++j));
			}
			else
				return (-1);
		}
	}
	if (j == 3)
		return (data->f[j] = (data->f[0] << 16 | data->f[1] << 8 | data->f[2]));
	return (-1);
}

int		ceiling(t_map *data, char *colstr, int j)
{
	int i;

	i = 0;
	while ((colstr && colstr[i]))
		if ((colstr[i++] > ' ' && i--))
		{
			if (colstr[i] == ',')
				i++;
			if (((data->c[j] = ft_atoi(&colstr[i], ',')) >= 0) &&
			(data->c[j] < 256))
			{
				while (ft_isdigit(colstr[i]))
					colstr++;
				return (ceiling(data, &colstr[i], ++j));
			}
			else
				return (-1);
		}
	if (j == 3)
		return (data->c[j] = (data->c[0] << 16 | data->c[1] << 8 | data->c[2]));
	return (-1);
}
