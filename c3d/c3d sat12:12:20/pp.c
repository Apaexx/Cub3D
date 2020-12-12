#include "c3d.h"

void            small_pp(t_mlx *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int             shiftbit(int col)
{
    if (col > 0x00ffff)
        col -= (0x00ff00);
    else if (col > 0x0000ff)
        col -= (0x0000ff);
    return col;
}

void            winit(void)
{
    void    *mlx;
    void    *mlx_win;
    t_mlx   img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    printf("bpp: %d\nll : %d\n", img.bits_per_pixel, img.line_length);
    big_pp(img);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}

void             big_pp(t_mlx img)
{
    int     x;
    int     xcount;
    int     y;
    int     ycount;
    int     j;
    // int     i;

    xcount = 0;
    ycount = 0;
    // i = 0;
    y = 41;
    x = 461;
    while (x < 1461 || y < 1041)
    {
        ycount++;
        if (y > 40 && y < 1041)
        {
            j = 0x0000ff;
            x = 461;
            while (x > 460 && x < 1461)
            {
                xcount++;
                small_pp(&img, x++, y, j);
            }
            y++;
        }
    }
    printf("x  : %d\ny  : %d\n", xcount, ycount);
}