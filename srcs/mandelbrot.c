/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <ppetchda@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+     +#+           */
/*   Created: 2022/05/19 20:13:59 by ppetchda          #+#    #+#             */
/*   Updated: 2022/05/19 20:18:35 by ppetchda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	set_color(int iter)
{
	int	r;
	int	g;
	int	b;

	r = (int)(0xFF / 16 * fmod(iter, 16.0));
	g = (int)(0xFF / 16 * fmod(iter, 16.0));
	b = (int)(0xFF / 16 * fmod(iter, 16.0));
	return (r << 16 | g << 8 | b);
}

int	draw_mandelbrot(int w, int h, int iter)
{
	double	z_x;
	double	z_y;
	double	c_re;
	double	c_im;
	double	temp;

	double pixel;
	double complex_x;
	double complex_y;

	if (WIN_WIDTH >= WIN_HEIGHT)
		pixel = WIN_WIDTH / 4;
	else
		pixel = WIN_HEIGHT / 4;
	// printf("fractol pixel = %.2f\n", fractol->pixel);
	complex_x = WIN_WIDTH / pixel;
	complex_y = WIN_HEIGHT / pixel;

	z_x = -0.5 + ((w / pixel) - (complex_x / 2));
	z_y = 0 + ((h / pixel) - (complex_y / 2));

	c_re = z_x;
	c_im = z_y;
	while ((pow(z_x, 2.0) + pow(z_y, 2.0) <= 4) && (iter < ITER_MAX))
	{
		temp = z_x;
		z_x = pow(z_x, 2.0) - pow(z_y, 2.0) + c_re;
		z_y = 2 * temp * z_y + c_im;
		iter++;
	}
	return (iter);
}

void	draw_mandelbrot_init(t_data *img)
{
	int	w;
	int	h;
	int	iter;

	w = 0;
	while (w < WIN_WIDTH)
	{
		h = 0;
		while (h < WIN_HEIGHT)
		{
			// printf("width height is : %d %d\n", w, h);
			// iter = fractol->f_fractol_calc(fractol, w, h, 0);
			iter = draw_mandelbrot(w, h, 0);
			if (iter == ITER_MAX)
				my_mlx_pixel_put(img, w, h, 0x00000000);
			else
				my_mlx_pixel_put(img, w, h, set_color(iter));
				// my_mlx_pixel_put(img, w, h, 0xFFFFFF);
				// my_mlx_pixel_put(img, w, h, set_color(iter, &fractol->color));
			h++;
		}
		w++;
	}
}

void	do_mandelbrot_init(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	img.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	// draw_grid_system(&img);
	draw_mandelbrot_init(&img);
	draw_grid_system(&img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}