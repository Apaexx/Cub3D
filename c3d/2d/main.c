#include <mlx.h>
#include <stdio.h>

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

int shiftbit(int col)
{
    if (col > 0x00ffff)
        col -= (0x00ff00);
    else if (col > 0x0000ff)
        col -= (0x0000ff);
    else
        col += (0x00ffff);
    return col;
}

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int             main(void)
{
    void    *mlx;
    void    *mlx_win;
    int     x;
    int     xcount;
    int     y;
    int     ycount;
    int     j;
    t_data  img;

    xcount = 0;
    ycount = 0;
    y = 41;
    x = 461;
    j = 0x000000;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    while (x < 1461 || y < 1041)
    {
        ycount++;
        if (y > 40 && y < 1041)
        {
            j = 0x000000;
            x = 461;
            while (x > 460 && x < 1461)
            {
                xcount++;
                my_mlx_pixel_put(&img, x++, y, j);
                j += 16711;
                //printf("0X%X\n", j);
            }
            y++;
        }
    }
    printf("%d\n%d\n", xcount, ycount);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}
