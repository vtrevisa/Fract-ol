#include <mlx.h>
#include "../include/fract_ol.h"
#include "../Libft/Include/libft.h"

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
	/* write(1, "a\n", 2); */
	while (data->y <= (data->maxy - 1))
	{
		data->x = 1;
		while (data->x <= (data->maxx - 1))
		{
			if(data->fract == 1)
				mandelbrot(data);
			else if(data->fract == 2)
				julia(data);
			else if (data->fract == 3)
				tricorn(data);
			else
				exit_fract(data);
			draw_pix(data);
			/* write(1, "o\n", 2); */
			data->x++;
		}
		data->y++;
	}
}

void	fractal(t_data *data)
{
	data->xscale = (data->maxR - data->minR) / data->maxx;
	data->yscale = (data->maxI - data->minI) / data->maxy;
	draw_fract(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	menu (data);
}
