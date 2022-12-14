/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:13:44 by vitor             #+#    #+#             */
/*   Updated: 2022/11/01 15:57:36 by vitor            ###   ########.fr       */
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
	double	multx;
	double	multy;

	if (key == 4)
	{
		multx = (data->maxr - data->minr);
		multy = (data->maxi - data->mini);
		data->minr *= 0.9;
		data->mini *= 0.9;
		data->maxi *= 0.9;
		data->maxr *= 0.9;
		data->maxcount += 10;
	}
	if (key == 5)
	{
		data->minr *= 1.1;
		data->mini *= 1.1;
		data->maxi *= 1.1;
		data->maxr *= 1.1;
		if (data->maxcount > 100)
			data->maxcount -= 10;
	}
	fractal (data);
	return (0);
}

int	keys(int key, t_data *data)
{
	if (key == 65307)
	{
		exit_fract(data);
	}
	return (0);
}

void	hooks(t_data *data)
{
	mlx_expose_hook(data->win_ptr, refresh, data);
	mlx_mouse_hook(data->win_ptr, zoom, data);
	mlx_key_hook(data->win_ptr, keys, data);
	mlx_hook(data->win_ptr, 17, 0, exit_fract, data);
}
