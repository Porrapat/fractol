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

// void	draw_mandelbrot(t_data *data)
// {
// 	(t_data *)data;
// }

void	do_mandelbrot_init(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	img.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_grid_system(&img);
	// draw_mandelbrot(&img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}

void	do_julia_init(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	img.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_grid_system(&img);
	// draw_julia(&img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}

void	do_burning_ship_init(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	img.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_grid_system(&img);
	// draw_julia(&img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}

void	do_roberte_init(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	img.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_grid_system(&img);
	// draw_julia(&img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}


void	check_fractal(char **argv)
{
	if (!ft_strncmp(argv[1], "mandelbrot", ft_strlen("mandelbrot")))
		do_mandelbrot_init();
	else if (!ft_strncmp(argv[1], "julia", ft_strlen("julia")))
		do_julia_init();
		// printf("julia\n");
	else if (!ft_strncmp(argv[1], "burning-ship", ft_strlen("burning-ship")))
		do_burning_ship_init();
		// printf("burning-ship\n");
	else if (!ft_strncmp(argv[1], "roberte", ft_strlen("roberte")))
		do_roberte_init();
		// printf("roberte\n");
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
	// do mandelbrot
	// do julia
	// do complex abs
*/
