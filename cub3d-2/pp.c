#include "c3d.h"

void			small_pp(t_mlx *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
	*(unsigned int*)dst = img->col;
}

int				shiftbit(int col)
{
	if (col > 0x00ffff)
		col -= (0x00ff00);
	else if (col > 0x0000ff)
		col -= (0x0000ff);
	return (col);
}

void			winit(t_mlx *img)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img->img = mlx_new_image(mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->ll, &img->endian);
	printf("bpp: %d\nll : %d\n", img->bpp, img->ll);
	big_pp(img);
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
	mlx_loop(mlx);
}

void			big_pp(t_mlx *img)
{
	int		x;
	int		y;
	int		j;

	y = 0;
	img->col = 0xff0000;
	img->y = 0;
	img->x = 0;
	while (y < 21)
	{
		x = 0;
		while (x < 21)
			small_pp(img, (x++ + img->x), (y + img->y));
		y++;
	}
}
