/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:13:42 by vitor             #+#    #+#             */
/*   Updated: 2022/10/26 19:58:41 by vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../include/fract_ol.h"

void	draw_pix(t_data *data)
{
	char	*adr;

	adr = data->img_adr + (data->y * data->line_len + data->x * (data->bit_per_pix / 8));
	if (data->count <= 10)
		data->color = 0xA020F0 * data->col_chg;
	else if (data->count > 10 && data->count <= 20)
		data->color = 0xFF69B4 * data->col_chg;
	else if (data->count > 20 && data->count <= 50)
		data->color = 0x00FF00 * data->col_chg;
	*(unsigned int*)adr = data->count * data->color;
}

static void draw_fract(t_data *data)
{
	data->y = 1;
	while (data->y <= (MAXY - 1))
	{
		data->x = 1;
		while (data->x <= (MAXX - 1))
		{
			if(data->fract == 1)
				mandelbrot(data);
			else if(data->fract == 2)
				julia(data);
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
	data->xscale = (data->maxR - data->minR) / MAXX;
	data->yscale = (data->maxI - data->minI) / MAXY;
	draw_fract(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	menu (data);
}
