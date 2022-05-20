#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <complex.h>    /* Standard Library of Complex Numbers */

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

// int	main(void)
// {
// 	t_vars	vars;
// 	t_data	img;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 800, 800, "Hello world!");

// 	// img.img = mlx_new_image(vars.mlx, 640, 480);
// 	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 	// 							&img.endian);

// 	// my_mlx_pixel_put(&img, 10, 10, 0xFF0000);
// 	// mlx_put_image_to_window(vars.mlx, vars.win, &img, 1, 1);



// 	mlx_loop(vars.mlx);
// }

int main() {

    double complex z1 = 1.0 + 3.0 * I;
    double complex z2 = 1.0 - 4.0 * I;

    printf("Working with complex numbers:\n\v");

    printf("Starting values: Z1 = %.2f + %.2fi\tZ2 = %.2f %+.2fi\n", creal(z1), cimag(z1), creal(z2), cimag(z2));

    double complex sum = z1 + z2;
    printf("The sum: Z1 + Z2 = %.2f %+.2fi\n", creal(sum), cimag(sum));

    double complex difference = z1 - z2;
    printf("The difference: Z1 - Z2 = %.2f %+.2fi\n", creal(difference), cimag(difference));

    double complex product = z1 * z2;
    printf("The product: Z1 x Z2 = %.2f %+.2fi\n", creal(product), cimag(product));

    double complex quotient = z1 / z2;
    printf("The quotient: Z1 / Z2 = %.2f %+.2fi\n", creal(quotient), cimag(quotient));

    double complex conjugate = conj(z1);
    printf("The conjugate of Z1 = %.2f %+.2fi\n", creal(conjugate), cimag(conjugate));

    return 0;
}