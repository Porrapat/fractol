/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
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
