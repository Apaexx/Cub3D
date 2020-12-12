#ifndef C3D_H

# define C3D_H

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_mlx;

typedef struct	s_data {
	char		**lines;
}				t_fillmap;

ssize_t			nx(char *str);
char			*ft_strdup(char *src);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_substr(char *s, unsigned int start, size_t len);
int				ft_split(char *src, char **d1, char **d2, int spx);
int				get_next_line(int fd, char **line);
void			big_pp(t_mlx img);
void			small_pp(t_mlx *data, int x, int y, int color);
void			winit(void);
int				shiftbit(int col);
int				readmap(char *filename);

#endif
