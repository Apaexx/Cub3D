#include "c3d.h"

void	small_pp(t_mlx *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
	*(unsigned int*)dst = img->col;
}

int		shiftbit(int col)
{
	if (col > 0x00ffff)
		col -= (0x00ff00);
	else if (col > 0x0000ff)
		col -= (0x0000ff);
	return (col);
}
