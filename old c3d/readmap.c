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
		return (txtr(data, &line[i + 2], 0));
	else if (!ft_strncmp(&line[i], "WE ", 3))
		return (txtr(data, &line[i + 3], 1));
	else if (!ft_strncmp(&line[i], "NO ", 3))
		return (txtr(data, &line[i + 3], 2));
	else if (!ft_strncmp(&line[i], "SO ", 3))
		return (txtr(data, &line[i + 3], 3));
	else if (!ft_strncmp(&line[i], "EA ", 3))
		return (txtr(data, &line[i] + 3, 4));
	else if (line[i] == '1')
		return (map(data, line));
	else
		return (-1);
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

int		read_file(char *filename, t_map *data)
{
	char	*line;
	int		i;

	sinit(data);
	i = 0;
	if (ft_strncmp(&filename[ft_strlen(filename) - 4], ".cub", 4))
		return (printf("Incorrect File Extension\n") / (-25));
	if ((data->fd = open(filename, O_RDONLY)) < 1)
		return (printf("Incorrect File Name\n") / (-20));
	while (data->gg > 0 && ++i)
	{
		data->gg = get_next_line(data->fd, &line);
		if (data_set(data, line) < 0)
			return (printf("Error1\n") / (-7));
		free(line);
	}
	if (!check_list(data))
		return (printf("Error2\n") / (-7));
	return (i);
}

char	*fillblank(char *str, char c, int l)
{
	char	*s;
	int		i;

	s = malloc(sizeof(char) * (l + 1));
	i = 0;
	while (l--)
		s[i++] = c;
	s[i] = '\0';
	return (ft_strjoin(str, 0, s));
}
