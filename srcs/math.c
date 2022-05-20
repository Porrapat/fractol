/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <ppetchda@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+     +#+           */
/*   Created: 2022/05/19 20:13:59 by ppetchda          #+#    #+#             */
/*   Updated: 2022/05/19 20:18:35 by ppetchda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	result;

	result.re = a.re + b.re;
	result.im = a.im + b.im;
	return (result);
}

t_complex	complex_mult(t_complex a, t_complex b)
{
	t_complex	result;

	result.re = a.re * b.re - a.im * b.im;
	result.im = a.im * b.re + a.re * b.im;
	return (result);
}

t_complex	complex_pow(t_complex a, int pow)
{
	t_complex	result;
	int			i;

	i = 2;
	result.re = a.re;
	result.im = a.im;
	while (i <= pow)
	{
		result = complex_mult(result, a);
		i++;
	}
	return (result);
}

void	complex_print(t_complex a)
{
	int	print_real;

	print_real = 0;
	if (a.re != 0)
	{
		printf("%.2f", a.re);
		print_real = 1;
	}
	if (a.im != 0)
	{
		if (print_real == 1 && a.im > 0)
			printf("+");
		printf("%.2fi", a.im);
	}
}
