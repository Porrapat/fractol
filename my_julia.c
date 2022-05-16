#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <complex.h>    /* Standard Library of Complex Numbers */

// Defining the size of the screen.
#define Y 600
#define X 800

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_point_double
{
	double	x;
	double	y;
}				t_point_double;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

// To recursively find the end value
// of the passed point till the pixel
// goes out of the bounded region
// or the maximum depth is reached.
int julia_point(t_vars *vars,
				float x, float y,
                int r, int depth,
                int max,
                double _Complex c,
                double _Complex z)
{
    if (cabs(z) > r) {
        // putpixel(x, y,
        //          COLOR(255 - 255 * ((max - depth) * (max - depth)) % (max * max),
        //                0, 0));
		mlx_pixel_put(vars->mlx, vars->win, x, y,
                 create_trgb(255 - 255 * ((max - depth) * (max - depth)) % (max * max),
                       0, 0));
        depth = 0;
    }
    if (sqrt(pow((x - X / 2), 2)
             + pow((y - Y / 2), 2))
        > Y / 2) {
        mlx_pixel_put(vars->mlx, vars->win,x, y, 0);
    }
    if (depth < max / 4) {
        return 0;
    }
    julia_point(vars,x, y, r,
                depth - 1, max,
                c, cpow(z, 2) + c);
}
  
// To select the points in a Julia set.
void juliaset(t_vars *vars, int depth, double _Complex c, int r, int detail)
{
    for (float x = X / 2 - Y / 2; x < X / 2 + Y / 2; x += detail) {
        for (float y = 0; y < Y; y += detail) {
            julia_point(vars, x, y, r,
                        depth, depth, c,
                        (2 * r * (x - X / 2) / Y)
                            + (2 * r * (y - Y / 2) / Y)
                                  * _Complex_I);
        }
    }
}
  

int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, X, Y, "Hello world!");

	// img.img = mlx_new_image(vars.mlx, 640, 480);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);

	// my_mlx_pixel_put(&img, 10, 10, 0xFF0000);
	// mlx_put_image_to_window(vars.mlx, vars.win, &img, 1, 1);
	// printf("Hello");
	// MandleSet(&vars);
	// juliaset(&vars, 0, 0, 0, 0);
	// juliaset(&vars, 0, 0, 0, 0);

	int depth = 100, r = 2, detail = 1;
  
    // Initial value for Julia
    // set taken by my personal preference.
    double _Complex c = 0.282 - 0.58 * _Complex_I;
	juliaset(&vars, depth, c, r, detail);

	mlx_loop(vars.mlx);
}
