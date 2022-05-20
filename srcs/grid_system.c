/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_system.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetchda <ppetchda@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                              +#+#+#+#+#+     +#+           */
/*   Created: 2022/05/19 20:13:59 by ppetchda          #+#    #+#             */
/*   Updated: 2022/05/19 20:18:35 by ppetchda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_grid_system(t_vars vars)
{
	int	w;
	// int	h;

	w = 0;
	while (w < WIN_WIDTH)
	{
		// while (h < WIN_HEIGHT)
		// {

		// }
		mlx_pixel_put(vars.mlx, vars.win, w, w, 0xFFFFFF);
		w = w + 100;
	}
}
