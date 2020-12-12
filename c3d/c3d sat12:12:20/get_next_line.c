#include "c3d.h"

int		ft_split(char *src, char **d1, char **d2, int spx)
{
	int		l;

	l = ft_strlen(src);
	*d1 = ft_substr(src, 0, spx);
	if (l != spx)
		*d2 = ft_substr(src, spx + 1, l - spx);
	else
		*d2 = NULL;
	free(src);
	return (1);
}

int		ffre(char **buf, char **jake, int i)
{
	free(*jake);
	free(*buf);
	return (i);
}

int		check_erread(int fd, char **buf, char **jake, int i)
{
	if (jake[0] != NULL)
		ft_split(jake[0], buf, jake, ft_strlen(jake[0]));
	else
	{
		if (BUFFER_SIZE < 1)
			return (-1);
		if (!(buf[0] = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
		if ((i = read(fd, buf[0], BUFFER_SIZE)) < 1)
			return (ffre(buf, jake, i));
		buf[0][i] = '\0';
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	int			i;
	static char *jake;

	*line = ft_strdup("");
	while (nx(*line) < 0 || (buf = NULL))
	{
		if ((i = check_erread(fd, &buf, &jake, i)) < 1)
			return (i);
		if ((i = nx(buf)) >= 0 && (ft_split(buf, &buf, &jake, i)) &&
		(*line = ft_strjoin(*line, buf)))
			break ;
		else
			*line = ft_strjoin(*line, buf);
	}
	return (1);
}
