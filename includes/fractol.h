/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <ppetchda@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+     +#+           */
/*   Created: 2022/05/19 20:13:59 by ppetchda          #+#    #+#             */
/*   Updated: 2022/05/19 20:18:35 by ppetchda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define ITER_MAX 100

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_complex {
	double	re;
	double	im;
}	t_complex;

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		white_screen_image(t_data *data, int w, int h);
void		draw_line_image(t_data *data, t_point p1, t_point p2, int color);
void		white_screen(void *mlx, void *win, int w, int h);
void		draw_grid_system(t_data *data);

void		do_mandelbrot_init(void);
void		do_julia_init(void);
void		do_burning_ship_init(void);
void		do_roberte_init(void);

t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_mult(t_complex a, t_complex b);
t_complex	complex_pow(t_complex a, int pow);
void		complex_print(t_complex a);

#endif