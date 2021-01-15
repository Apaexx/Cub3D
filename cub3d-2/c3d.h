#ifndef C3D_H

# define C3D_H

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_mlx {
	void		*img;
	char		*addr;
	int			bpp;
	int			ll;
	int			endian;
	int			x;
	int			y;
	int			col;
}				t_mlx;

typedef struct	s_map {
	int			fd;
	int			gg;
	int			res[2];
	int			f[4];
	int			c[4];
	char		*sprite;
	char		*west;
	char		*north;
	char		*south;
	char		*east;
	char		*map;
	char		**jmap;
	int			ymap;
}				t_map;

ssize_t			nx(char *str);
int				nl(char *map);
int				check_list(t_map *data);
int				ft_isdigit(int n);
int				ft_atoi(char *str);
char			*ft_strdup(char *src);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char *s1, int c, char *s2);
char			*ft_substr(char *s, unsigned int start, size_t len);
int				ft_strncmp(char *s1, char *s2, int n);
int				ft_strchr(char *str, char c);
int				ft_split(char *src, char **d1, char **d2, int spx);
int				get_next_line(int fd, char **line);
void			big_pp(t_mlx *img);
void			small_pp(t_mlx *data, int x, int y);
void			sinit(t_map *data);
void			winit(t_mlx *img);
int				blank(char *str);
int				shift_bit(int col);
int				read_map(char *filename);
int				check_map(t_map *data, int j);
int				data_set(t_map *data, char *line);
int				filler_func(t_map *data, char *line, int i);
int				win_res(t_map *data, char *restr, int j);
int				north(t_map *data, char *path);
int				east(t_map *data, char *path);
int				west(t_map *data, char *path);
int				south(t_map *data, char *path);
int				sprite(t_map *data, char *path);
int				win_res(t_map *data, char *restr, int j);
int				flooor(t_map *data, char *colstr, int j);
int				ceiling(t_map *data, char *colstr, int j);
int				map(t_map *data, char *mapstr);
#endif
