#include "c3d.h"

int		main(void)
{
	int			k;
	t_struct	j;

	k = read_file("j.cub", &j.d);
	if (k > -1)
	{
		j.m = mlx_init();
		j.w = mlx_new_window(j.m, j.d.res[0], j.d.res[1], "Cub3D");
		j.i.img = mlx_new_image(j.m, j.d.res[0], j.d.res[1]);
		j.i.addr = mlx_get_data_addr(j.i.img, &j.i.bpp, &j.i.ll, &j.i.enn);
		mlx_loop_hook(j.m, &next_frame2D, &j);
		mlx_loop(j.m);
		printf("%d\n", k);
	}
}

int		next_frame2D(t_struct *j)
{
	mlx_hook(j->w, 2, 1L << 0, key_pressed, j);
	mlx_hook(j->w, 3, 1L << 0, key_released, j);
	j->d.pa += j->d.rt * M_PI / 60;
	j->r.ra = -50 * M_PI / 180;
	if (next_step(j, j->d.px, j->d.py, M_PI_2 * j->d.lr + j->d.pa, 3 * j->d.mv))
	{
		j->d.py -= 3 * j->d.mv * cos((M_PI_2 * j->d.lr) + j->d.pa);
		j->d.px -= 3 * j->d.mv * sin((M_PI_2 * j->d.lr) + j->d.pa);
	}
	draw_map(j);
	j->i.col = 0xff8800;
	while (j->r.ra < (51 * M_PI / 180) || !(j->r.ra = -50 * M_PI / 180))
	{
		j->r.rx = j->d.px;
		j->r.ry = j->d.py;
		while (next_step(j, j->r.rx, j->r.ry, j->r.ra + j->d.pa, 1))
			linedraw(j);
		j->r.ra += M_PI * 100 / 180 / j->d.res[0];
	}
	mlx_put_image_to_window(j->m, j->w, j->i.img, 0, 0);
	return (1);
}

int		linedraw(t_struct *j)
{
	small_pp(&j->i, j->r.rx, j->r.ry);
	j->r.ry -= cos(j->r.ra + j->d.pa);
	j->r.rx -= sin(j->r.ra + j->d.pa);
	return (0);
}

int		next_step(t_struct *j, float x, float y, float a, int d) //for player
{
	if (!(x * y) ||
	(j->d.jmap[(int)floor((y - d * cos(a)) / 32)][(int)floor(x / 32)] == '1') ||
	(j->d.jmap[(int)floor(y / 32)][(int)floor((x - d * sin(a)) / 32)] == '1'))
		return (0);
	return (1);
}

int		key_pressed(int keycode, t_struct *j)
{
	// printf("%d pressed\n", keycode);
	if (((keycode == 123) || (keycode == 124)) && (j->d.mv = 1))
		j->d.lr = -(((keycode - 123) * 2) - 1);
	if (!(keycode) || (keycode == 2))
		j->d.rt = (-(keycode - 1));
	if ((keycode == 1) || (keycode == 13))
		j->d.mv = (keycode - 7) / 6;
	return (1);
}

int		key_released(int keycode, t_struct *j)
{
	// printf("%d released\n", keycode);
	if (((keycode == 123) || (keycode == 124)) && !(j->d.mv = 0))
		j->d.lr = 0;
	if (!(keycode) || (keycode == 2))
		j->d.rt = 0;
	if ((keycode == 1) || (keycode == 13))
		j->d.mv = 0;
	return (1);
}
