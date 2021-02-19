#ifndef C3D_H

# define C3D_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_mlx {
	int			x;
	int			y;
	int			ll;
	int			bpp;
	int			col;
	int			enn;
	void		*img;
	char		*addr;
}				t_mlx;

typedef struct	s_ray {
	float		rx;
	float		ry;
	float		wx;
	float		wy;
	float		ra;
	float		c;
	float		s;
	float		t;
}				t_ray;

typedef struct	s_map {
	int			fd;
	int			gg;
	float		px;
	float		py;
	float		pa;
	int			tx;
	int			ty;
	int			mv;
	int			lr;
	int			rt;
	int			f[4];
	int			c[4];
	int			ymap;
	int			xmap;
	char		*map;
	char		*west;
	char		*east;
	char		*north;
	char		*south;
	char		**jmap;
	int			res[2];
	char		*sprite;
}				t_map;

typedef struct	s_struct {
	t_mlx		i;
	t_map		d;
	t_ray		r;
	void		*m;
	void		*w;
}				t_struct;

ssize_t			nx(char *str);
int				nl(char *map);
int				blank(char *str);
void			ppp(t_struct *j);
void			winit(t_mlx *img);
int				vert(t_struct *j);
int				horz(t_struct *j);
int				ft_isdigit(int n);
int				frwd(t_struct *j);
int				ft_strlen(char *s);
void			sinit(t_map *data);
int				shift_bit(int col);
void			big_pp(t_struct *j);
int				raycast(t_struct *j);
int				linedraw(t_struct *j);
int				draw_map(t_struct *j);
char			*ft_strdup(char *src);
int				next_map(t_struct *j);
int				check_list(t_map *data);
int				next_frame2D(t_struct *j);
int				ft_atoi(char *str, char c);
int				ft_strchr(char *str, char c);
int				check_map(t_map *data, int j);
int				map(t_map *data, char *mapstr);
int				ppos(t_struct *j, int i, int k);
int				data_set(t_map *data, char *line);
int				get_next_line(int fd, char **line);
void			small_pp(t_mlx *data, int x, int y);
int				txtr(t_map *data, char *path, int c);
char			*fillblank(char *str, char c, int l);
int				key_pressed(int keycode, t_struct *j);
int				ft_strncmp(char *s1, char *s2, int n);
int				key_released(int keycode, t_struct *j);
int				read_file(char *filename, t_map	*data);
char			*ft_strjoin(char *s1, int c, char *s2);
int				win_res(t_map *data, char *restr, int j);
int				flooor(t_map *data, char *colstr, int j);
int				win_res(t_map *data, char *restr, int j);
int				ceiling(t_map *data, char *colstr, int j);
int				filler_func(t_map *data, char *line, int i);
int				iswall(t_struct *j, float y, float x, int k);
int				ft_split(char *src, char **d1, char **d2, int spx);
char			*ft_substr(char *s, unsigned int start, size_t len);
int				next_step(t_struct *j, float x, float y, float a, int d);
#endif
