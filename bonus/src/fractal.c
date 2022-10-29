/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 03:58:57 by vtrevisa          #+#    #+#             */
/*   Updated: 2022/10/27 04:19:19 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../include/fract_ol.h"

void	draw_pix(t_data *data)
{
	char	*adr;

	adr = data->img_adr + (data->y * data->line_len + data->x * \
										(data->bit_per_pix / 8));
	if (data->count <= 10)
		data->color = 0xA020F0 * data->col_chg;
	else if (data->count > 10 && data->count <= 20)
		data->color = 0xFF69B4 * data->col_chg;
	else if (data->count > 20 && data->count <= 50)
		data->color = 0x00FF00 * data->col_chg;
	*(unsigned int *)adr = data->count * data->color;
}

static void	draw_fract(t_data *data)
{
	data->y = 1;
	while (data->y <= (MAXY - 1))
	{
		data->x = 1;
		while (data->x <= (MAXX - 1))
		{
			if (data->fract == 1)
				mandelbrot(data);
			else if (data->fract == 2)
				julia(data);
			else if (data->fract == 3)
				tricorn(data);
			else
				exit_fract(data);
			draw_pix(data);
			data->x++;
		}
		data->y++;
	}
}

void	fractal(t_data *data)
{
	data->xscale = (data->maxr - data->minr) / MAXX;
	data->yscale = (data->maxi - data->mini) / MAXY;
	draw_fract(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	menu (data);
}
