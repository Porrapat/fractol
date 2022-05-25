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

void	draw_grid_system_full(t_data *data)
{
	int	w;
	int	h;

	w = 200;
	while (w < WIN_WIDTH)
	{
		draw_line_image(data, (t_point) {w, 0}, (t_point) {w, WIN_HEIGHT}, 0x666666);
		w = w + 200;
	}
	h = 200;
	while (h < WIN_HEIGHT)
	{
		draw_line_image(data, (t_point) {0, h}, (t_point) {WIN_WIDTH, h}, 0x666666);
		h = h + 200;
	}
}

void	draw_grid_system_small(t_data *data)
{
	int	w;
	int	h;

	w = 50;
	while (w < WIN_WIDTH)
	{
		draw_line_image(data, (t_point) {w, 0}, (t_point) {w, WIN_HEIGHT}, 0x333333);
		w = w + 50;
	}
	h = 50;
	while (h < WIN_HEIGHT)
	{
		draw_line_image(data, (t_point) {0, h}, (t_point) {WIN_WIDTH, h}, 0x333333);
		h = h + 50;
	}
}

void	draw_grid_system(t_data *data)
{
	draw_grid_system_small(data);
	draw_grid_system_full(data);
}
