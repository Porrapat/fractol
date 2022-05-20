/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <ppetchda@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+     +#+           */
/*   Created: 2022/05/19 20:13:59 by ppetchda          #+#    #+#             */
/*   Updated: 2022/05/19 20:18:35 by ppetchda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	do_mandelbrot()
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");

	// draw_grid_system(vars);

	mlx_loop(vars.mlx);
}

void	check_fractal(char **argv)
{
	if (!ft_strncmp(argv[1], "mandelbrot", ft_strlen("mandelbrot")))
		do_mandelbrot();
	else if (!ft_strncmp(argv[1], "julia", ft_strlen("julia")))
		printf("julia\n");
	else if (!ft_strncmp(argv[1], "burning-ship", ft_strlen("burning-ship")))
		printf("burning-ship\n");
	else if (!ft_strncmp(argv[1], "roberte", ft_strlen("roberte")))
		printf("roberte\n");
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		check_fractal(argv);
	else
		printf("./fractol [mandelbrot, julia, roberte, burning-ship]\n");
	return (0);
}
/*
	// do complex abs
	// do grid system
	// ...

	// t_complex z;
	// z.re = 1;
	// z.im = 2;

	// printf("%.2f %.2fi\n", z.re, z.im);

		// t_vars	vars;

	// t_complex c1;
	// c1.re = 2;
	// c1.im = -1;
	// complex_print(c1);
	// printf("\n");

	// vars.mlx = mlx_init();
	// vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	// mlx_loop(vars.mlx);

	
	// // t_complex c2;
	// // c2.re = 1;
	// // c2.im = 1;
	// t_complex c3;
	// // c3 = complex_mult(c1, c2);
	// c3 = complex_pow(c1, 4);

	// printf("%.2f+%.2fi\n", c1.re, c1.im);
	// // printf("%.2f+%.2fi\n", c2.re, c2.im);
	// printf("%.2f+%.2fi\n", c3.re, c3.im);
*/