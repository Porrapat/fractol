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


void	check_fractal(char **argv)
{
	if (!ft_strncmp(argv[1], "mandelbrot", ft_strlen("mandelbrot")))
		do_mandelbrot_init();
	else if (!ft_strncmp(argv[1], "julia", ft_strlen("julia")))
		do_julia_init();
	else if (!ft_strncmp(argv[1], "burning-ship", ft_strlen("burning-ship")))
		do_burning_ship_init();
	else if (!ft_strncmp(argv[1], "roberte", ft_strlen("roberte")))
		do_roberte_init();
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
