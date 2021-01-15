#include "c3d.h"

int		north(t_map *data, char *path)
{
	int		i;

	i = 0;
	while (path && path[i])
	{
		if (path[i] > ' ')
		{
			if (!(data->north = ft_strdup(&path[i])))
				return (-1);
			return (ft_strlen(&path[i]));
		}
		i++;
	}
	return (-1);
}

int		east(t_map *data, char *path)
{
	int		i;

	i = 0;
	while (path && path[i])
	{
		if (path[i] > ' ')
		{
			if (!(data->east = ft_strdup(&path[i])))
				return (-1);
			return (ft_strlen(&path[i]));
		}
		i++;
	}
	return (-1);
}

int		west(t_map *data, char *path)
{
	int		i;

	i = 0;
	while (path && path[i])
	{
		if (path[i] > ' ')
		{
			if (!(data->west = ft_strdup(&path[i])))
				return (-1);
			return (ft_strlen(&path[i]));
		}
		i++;
	}
	return (-1);
}

int		south(t_map *data, char *path)
{
	int		i;

	i = 0;
	while (path && path[i])
	{
		if (path[i] > ' ')
		{
			if (!(data->south = ft_strdup(&path[i])))
				return (-1);
			return (ft_strlen(&path[i]));
		}
		i++;
	}
	return (-1);
}

int		sprite(t_map *data, char *path)
{
	int		i;

	i = 0;
	while (path && path[i])
	{
		if (path[i] > ' ')
		{
			if (!(data->sprite = ft_strdup(&path[i])))
				return (-1);
			return (ft_strlen(&path[i]));
		}
		i++;
	}
	return (-1);
}
