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

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_complex {
	double	re;
	double	im;
}	t_complex;

t_complex	complex_mult(t_complex a, t_complex b);
t_complex	complex_pow(t_complex a, int pow);

#endif