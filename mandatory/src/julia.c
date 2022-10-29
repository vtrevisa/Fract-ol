/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:13:50 by vitor             #+#    #+#             */
/*   Updated: 2022/10/27 04:23:15 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	julia(t_data *data)
{
	data->zx = (data->x * data->xscale) + data->minr;
	data->zy = (data->y * data->yscale) + data->mini;
	data->cx = data->jc[0];
	data->cy = data->jc[1];
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
