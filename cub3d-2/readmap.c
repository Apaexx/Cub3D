#include "c3d.h"

int		filler_func(t_map *data, char *line, int i)
{
	if (!ft_strncmp(&line[i], "R ", 2))
		return (win_res(data, &line[i + 2], 0));
	else if (!ft_strncmp(&line[i], "F ", 2))
		return (flooor(data, &line[i + 2], 0));
	else if (!ft_strncmp(&line[i], "C ", 2))
		return (ceiling(data, &line[i + 2], 0));
	else if (!ft_strncmp(&line[i], "S ", 2))
		return (sprite(data, &line[i + 2]));
	else if (!ft_strncmp(&line[i], "WE ", 3))
		return (west(data, &line[i + 3]));
	else if (!ft_strncmp(&line[i], "NO ", 3))
		return (north(data, &line[i + 3]));
	else if (!ft_strncmp(&line[i], "SO ", 3))
		return (south(data, &line[i + 3]));
	else if (!ft_strncmp(&line[i], "EA ", 3))
		return (east(data, &line[i] + 3));
	else if (line[i] == '1')
		return (map(data, line));
	else
		return (-1);
}

int		map(t_map *data, char *mapstr)
{
	int		i;
	int		j;
	int		k;

	if (!(data->map = ft_strdup(mapstr)))
		return (-1);
	while (data->gg > 0)
	{
		data->gg = get_next_line(data->fd, &mapstr);
		data->map = ft_strjoin(data->map, 1, mapstr);
	}
	i = nl(data->map);
	j = i;
	data->jmap = malloc(sizeof(char *) * (i));
	while (i)
		ft_split(data->map, &data->jmap[j - i--], &data->map, nx(data->map));
	while (blank(data->jmap[j - 1]))
		free(data->jmap[--j]);
	if (!(check_map(data, j)))
		printf("\n\n\n\n####hey, your shit is wrong####\n\n\n\n");
	// while (j--)
	// {
	// 	printf("%02d - %02d: ", j, i);
	// 	printf("%s\n", data->jmap[i++]);
	// }
	return (data->ymap = j);
}

int		blank(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
		if (str[i++] > ' ')
			return (0);
	return (1);
}

int		data_set(t_map *data, char *line)
{
	int		i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] > ' ')
			return (filler_func(data, line, i));
		i++;
	}
	return (0);
}

int		read_map(char *filename)
{
	char	*line;
	t_map	data;
	int		i;

	sinit(&data);
	i = 0;
	if (ft_strncmp(&filename[ft_strlen(filename) - 4], ".cub", 4))
		return (printf("Incorrect File Extension\n") / (-25));
	if ((data.fd = open(filename, O_RDONLY)) < 1)
		return (printf("Incorrect File Name\n") / (-20));
	while (data.gg > 0 && ++i)
	{
		data.gg = get_next_line(data.fd, &line);
		if (data_set(&data, line) < 0)
			return (printf("Error\n"));
	}
	if (!check_list(&data))
		return (printf("HAHAAHAAHHAHA IT WOORKS\n"));
	return (i);
}
