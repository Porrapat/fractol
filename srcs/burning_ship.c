/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <ppetchda@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+     +#+           */
/*   Created: 2022/05/19 20:13:59 by ppetchda          #+#    #+#             */
/*   Updated: 2022/05/19 20:18:35 by ppetchda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_burning_ship(int w, int h, int iter)
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
	complex_x = WIN_WIDTH / pixel;
	complex_y = WIN_HEIGHT / pixel;

	// z_x = -0.5 + ((w / pixel) - (complex_x / 2));
	// z_y = -0.5 + ((h / pixel) - (complex_y / 2));

	// c_re = z_x;
	// c_im = z_y;

	c_re = -0.5 + ((w / pixel) - (complex_x / 2));
	c_im = -0.5 + ((h / pixel) - (complex_y / 2));
	z_x = c_re;
	z_y = c_im;

	while ((pow(z_x, 2.0) + pow(z_y, 2.0) <= 4) && (iter < ITER_MAX))
	{
		temp = pow(z_x, 2.0) - pow(z_y, 2.0) + c_re;
		z_y = fabs(2 * z_x * z_y) + c_im;
		z_x = temp;
		iter++;
	}
	return (iter);
}

void	draw_burning_ship_init(t_data *img)
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
			iter = draw_burning_ship(w, h, 0);
			if (iter == ITER_MAX)
				my_mlx_pixel_put(img, w, h, 0x00000000);
			else
				my_mlx_pixel_put(img, w, h, set_color(iter));
			h++;
		}
		w++;
	}
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
	draw_burning_ship_init(&img);
	draw_grid_system(&img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
