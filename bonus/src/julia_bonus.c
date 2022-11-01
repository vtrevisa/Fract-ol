/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:13:29 by vtrevisa          #+#    #+#             */
/*   Updated: 2022/11/01 16:14:09 by vitor            ###   ########.fr       */
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
		data->tempx = (data->zx * data->zx) - (data->zy * data->zy);
		data->zy = (2 * data->zx * data->zy) + data->cy;
		data->zx = data->tempx + data->cx;
		data->count++;
	}
}
