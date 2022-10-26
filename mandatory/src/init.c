/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:13:47 by vitor             #+#    #+#             */
/*   Updated: 2022/10/26 19:22:31 by vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	init(t_data *data)
{
	data->maxcount = 30;
	data->minR = -2;//-2
	data->minI = -1.5;//-1.5
	data->maxR = 1;
	data->maxI = data->minI + (data->maxR - data->minR) * (MAXX / MAXY);
	data->color = 127;
	data->col_chg = 1;
	data->Jc[0] = 0.01;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, MAXX, MAXY, "Fract-ol");
	data->img_ptr = mlx_new_image(data->mlx_ptr, MAXX, MAXY);
	data->img_adr = mlx_get_data_addr(data->img_ptr, &data->bit_per_pix, &data->line_len, &data->endian);
}

void	menu (t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0x00FFFFFF, "Zoom: Mouse Scroll");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 30, 0x00FFFFFF, "Exit: Esc");
}