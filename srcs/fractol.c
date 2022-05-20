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

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	mlx_loop(vars.mlx);

	// t_complex c1;
	// c1.re = 1;
	// c1.im = 1;
	// // t_complex c2;
	// // c2.re = 1;
	// // c2.im = 1;
	// t_complex c3;
	// // c3 = complex_mult(c1, c2);
	// c3 = complex_pow(c1, 4);

	// printf("%.2f+%.2fi\n", c1.re, c1.im);
	// // printf("%.2f+%.2fi\n", c2.re, c2.im);
	// printf("%.2f+%.2fi\n", c3.re, c3.im);

	return (0);
}

	// do complex add
	// do complex print
	// do complex abs
	// check argument
	// do grid system
	// ...

	// t_complex z;
	// z.re = 1;
	// z.im = 2;

	// printf("%.2f %.2fi\n", z.re, z.im);