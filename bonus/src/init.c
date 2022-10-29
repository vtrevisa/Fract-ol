/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 03:54:52 by vtrevisa          #+#    #+#             */
/*   Updated: 2022/10/27 04:19:19 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	init(t_data *data)
{
	data->maxcount = 30;
	data->minr = -2;
	data->mini = -1.5;
	data->maxr = 1;
	data->maxi = data->mini + (data->maxr - data->minr) * (MAXX / MAXY);
	data->color = 127;
	data->col_chg = 1;
	data->jc[0] = 0.01;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, MAXX, MAXY, "Fract-ol");
	data->img_ptr = mlx_new_image(data->mlx_ptr, MAXX, MAXY);
	data->img_adr = mlx_get_data_addr(data->img_ptr, &data->bit_per_pix, \
					&data->line_len, &data->endian);
}

void	menu(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0x00FFFFFF, \
		"Zoom: Mouse Scroll");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 30, 0x00FFFFFF, \
		"Move: Arrow Keys");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 50, 0x00FFFFFF, \
		"Chg Color: Q and E");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 70, 0x00FFFFFF, \
		"For Julia");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 90, 0x00FFFFFF, \
		"Change Params: R and L click");
}
