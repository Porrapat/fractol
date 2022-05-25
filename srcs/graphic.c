/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <ppetchda@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+     +#+           */
/*   Created: 2022/05/19 20:13:59 by ppetchda          #+#    #+#             */
/*   Updated: 2022/05/19 20:18:35 by ppetchda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	white_screen(void *mlx, void *win, int w, int h)
{
	int	x;
	int	y;

	x = w;
	while (x--)
	{
		y = h;
		while (y--)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
		}
	}
}

void	white_screen_image(t_data *data, int w, int h)
{
	int	x;
	int	y;

	x = w;
	while (x--)
	{
		y = h;
		while (y--)
		{
			my_mlx_pixel_put(data, x, y, 0xFFFFFF);
		}
	}
}

void	draw_line_image(t_data *data, t_point p1, t_point p2, int color)
{
	double	delta_x;
	double	delta_y;
	int		pixels;

	delta_x = p2.x - p1.x;
	delta_y = p2.y - p1.y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	while (pixels)
	{
		my_mlx_pixel_put(data, p1.x, p1.y, color);
		p1.x += delta_x;
		p1.y += delta_y;
		--pixels;
	}
}
