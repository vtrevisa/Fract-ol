/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:13:44 by vitor             #+#    #+#             */
/*   Updated: 2022/10/26 19:15:03 by vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"
#include <stdio.h>

int	zoom(int key, int x, int y, t_data *data)
{
	double multx, multy;
	if (key == 4)
	{
		multx = (data->maxR - data->minR);
		multy = (data->maxI - data->minI);
		data->minR *= 0.9;
		data->minI *= 0.9;
		data->maxI *= 0.9;
		data->maxR *= 0.9;
		data->maxcount += 10;
	}
	if (key == 5)
	{
		data->minR *= 1.1;
		data->minI *= 1.1;
		data->maxI *= 1.1;
		data->maxR *= 1.1;
		if (data->maxcount > 30)
			data->maxcount -= 10;
	}
	fractal (data);
}

int	keys(int key, t_data *data)
{
	if (key == 65307)
	{
		exit_fract(data);
	}
}

void	hooks(t_data *data)
{
	mlx_mouse_hook(data->win_ptr, zoom, data);
	mlx_key_hook(data->win_ptr, keys, data);
	mlx_hook(data->win_ptr, 17, 0, exit_fract, data);
}