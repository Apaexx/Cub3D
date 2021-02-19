#include "c3d.h"

int		txtr(t_map *data, char *path, int c)
{
	int		i;
	char	*x;

	i = 0;
	while (path && path[i])
	{
		if (path[i] > ' ')
		{
			if (!(x = ft_strdup(&path[i])))
				return (-1);
			if (!c)
				data->sprite = x;
			else if (c == 1)
				data->west = x;
			else if (c == 2)
				data->north = x;
			else if (c == 3)
				data->south = x;
			else if (c == 4)
				data->east = x;
			return (ft_strlen(&path[i]));
		}
		i++;
	}
	return (-1);
}

int		ppos(t_struct *j, int i, int k)
{
	j->d.jmap[k][i] = '0';
	j->i.col = 0xff00;
	j->d.px = j->i.x + 14;
	j->d.py = j->i.y + 14;
	j->d.tx = (int)floor(j->d.px / 32);
	j->d.ty = (int)floor(j->d.py / 32);
	ppp(j);
	return (1);
}
