#include "c3d.h"

int sortstruct(char *line)
{

}

int	ft_strchr(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != c)
	{
		if (str[i])
			i++;
		else
			return (-1);
	}
	return (i);
}

int readmap(char *filename)
{
    int fd;
    char *line;
    int gg;
    int i;
    

    gg = 1;
    i = 0;
    fd = open(filename, O_RDONLY);
    while (gg > 0)
    {
        gg = get_next_line(fd, &line);

    }
    while (gg < i)
    // {
    //     while (*line[gg])
    //     {
    //         while (*line[gg] <= ' ')
    //             *(line++)[gg];
    //         if (ft_strchr("01newsrfc", *line[gg]) > 0)
    //             sortstruct(line[gg]);
    //     } 
    // }
    // while (gg < i)
    //     printf("%s\n", line[gg++]);
    // return (gg);
}