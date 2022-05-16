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
	printf("Hello");
	MandleSet(&vars);

	mlx_loop(vars.mlx);
}
