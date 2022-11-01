/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:02:24 by vtrevisa          #+#    #+#             */
/*   Updated: 2022/11/01 15:57:57 by vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	refresh(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}

int	zoom(int key, int x, int y, t_data *data)
{
	if (key == 4)
		zoom_in(data, x, y);
	if (key == 5)
	{
		data->minr -= (data->maxr - data->minr) * 0.1;
		data->mini -= (data->maxi - data->mini) * 0.1;
		data->maxi += (data->maxi - data->mini) * 0.1;
		data->maxr += (data->maxr - data->minr) * 0.1;
		if (data->maxcount > 100)
			data->maxcount -= 10;
	}
	if (key == 1)
	{
		data->jc[0] += 0.04;
		data->jc[1] += 0.04;
	}
	if (key == 3)
	{
		data->jc[0] -= 0.04;
		data->jc[1] -= 0.04;
	}
	fractal (data);
}

int	keys(int key, t_data *data)
{
	if (key == 65307)
		exit_fract(data);
	if (key == 65361)
		move_ld(data, 1);
	if (key == 65362)
		move_ur(data, 1);
	if (key == 65363)
		move_ur(data, 2);
	if (key == 65364)
		move_ld(data, 2);
	if (key == 113)
		data->col_chg *= 10;
	if (key == 101)
		data->col_chg /= 10;
	fractal(data);
}

void	hooks(t_data *data)
{
	mlx_expose_hook(data->win_ptr, refresh, data);
	mlx_mouse_hook(data->win_ptr, zoom, data);
	mlx_key_hook(data->win_ptr, keys, data);
	mlx_hook(data->win_ptr, 17, 0, exit_fract, data);
}
