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

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// typedef struct	s_point_double
// {
// 	double	x;
// 	double	y;
// }				t_point_double;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	create_trgb(int r, int g, int b)
// {
// 	return (r << 16 | g << 8 | b);
// }


// // Recursive function to provide the iterative every 100th
// // f^n (0) for every pixel on the screen.
// int Mandle(t_vars	*vars, double _Complex c, double _Complex t, int counter)
// {
// 	// counter = 0;
// 	// t = 0;
//     // To eliminate out of bound values.
//     if (cabs(t) > 4) {
//         // putpixel(creal(c) * Y / 2 + X / 2,
//         //          cimag(c) * Y / 2 + Y / 2,
//         //          COLOR(128 - 128 * cabs(t) / cabs(c),
//         //                128 - 128 * cabs(t) / cabs(c),
//         //                128 - 128 * cabs(t) / cabs(c)));
//         mlx_pixel_put(vars->mlx, vars->win, creal(c) * Y / 2 + X / 2,
//                  cimag(c) * Y / 2 + Y / 2,
//                  create_trgb(128 - 128 * cabs(t) / cabs(c),
//                        128 - 128 * cabs(t) / cabs(c),
//                        128 - 128 * cabs(t) / cabs(c)));
//         return 0;
//     }
  
//     // To put about the end of the fractal,
//     // the higher the value of the counter,
//     // The more accurate the fractal is generated,
//     // however, higher values cause
//     // more processing time.
//     if (counter == 100) {
//         mlx_pixel_put(vars->mlx, vars->win, creal((c)) * Y / 2 + X / 2,
//                  cimag((c)) * Y / 2 + Y / 2,
//                  create_trgb(255 * (cabs((t * t))
//                               / cabs((t - c) * c)),
//                        0, 0));
//         return 0;
//     }
  
//     // recursively calling Mandle with increased counter
//     // and passing the value of the squares of t into it.
//     Mandle(vars, c, cpow(t, 2) + c, counter + 1);
  
//     return 0;
// }
  
// int MandleSet(t_vars	*vars)
// {
//     for (double x = -2; x < 2; x += 0.0015) {
//         for (double y = -1; y < 1; y += 0.0015) {

//             // printf("%.2f + %.2f\n",x,y );
//             double _Complex temp = x + y * _Complex_I;
//             Mandle(vars, temp, 0, 0);
//         }
//     }
//     return 0;
// }

int	main(void)
{
	t_vars	vars;
	// t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, X, Y, "Hello world!");

	// img.img = mlx_new_image(vars.mlx, 640, 480);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);

	// my_mlx_pixel_put(&img, 10, 10, 0xFF0000);
	// mlx_put_image_to_window(vars.mlx, vars.win, &img, 1, 1);
	// printf("Hello");
	// MandleSet(&vars);

	mlx_loop(vars.mlx);
}
