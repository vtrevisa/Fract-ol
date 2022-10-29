/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:14:21 by vtrevisa          #+#    #+#             */
/*   Updated: 2022/10/27 04:19:19 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	mandelbrot(t_data *data)
{
	data->cx = ((double)data->x * data->xscale) + data->minr;
	data->cy = ((double)data->y * data->yscale) + data->mini;
	data->zx = 0;
	data->zy = 0;
	data->count = 0;
	while ((((data->zx * data->zx) + (data->zy * data->zy)) < 4) \
								&& (data->count < data->maxcount))
	{
		data->tempx = (data->zx * data->zx) - (data->zy * data->zy) + data->cx;
		data->zy = (2 * data->zx * data->zy) + data->cy;
		data->zx = data->tempx;
		data->count++;
	}
}
