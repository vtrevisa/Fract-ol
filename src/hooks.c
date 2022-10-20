#include "../include/fract_ol.h"
#include <stdio.h>

int	zoom(int key, int x, int y, t_data *data)
{
	double multx, multy;
	/* multx = (double)(data->maxR - data->minR) / data->maxx;
	multy = (double)(data->maxI - data->minI) / data->maxy; */
	if (key == 4)
	{
		multx = (data->maxR - data->minR);
		multy = (data->maxI - data->minI);
		data->minR += /* (data->maxR - data->minR) * 0.1; */multx * (x / (double)data->maxx) / 10;
		data->minI += /* (data->maxI - data->minI) * 0.1; */multy * (y / (double)data->maxy) / 10;
		data->maxI -= /* (data->maxI - data->minI) * 0.1; */multy * (1 - y / (double)data->maxy) / 10;
		data->maxR -= /* (data->maxR - data->minR) * 0.1; */multx * (1 - x / (double)data->maxx) / 10;
		data->MAXCOUNT += 10;
		/* printf("x:%f, y:%f\n", multx, multy); */
		/* printf("mr:%f, mi:%f, xr:%f, xi:%f\n", data->minR, data->minI, data->maxR, data->maxI); */
	}
	if (key == 5)
	{
		data->minR -= (data->maxR - data->minR) * 0.1;/* (data->minR - ((double)(x * multx) / 0.1)); */
		data->minI -= (data->maxI - data->minI) * 0.1;/* (data->minI - (((double)(data->maxy - y) * multy) * 0.1)); */
		data->maxI += (data->maxI - data->minI) * 0.1;/* (data->maxI + (((double)(data->maxx - x) * multx) * 0.1)); */
		data->maxR += (data->maxR - data->minR) * 0.1;/* (data->maxR + ((double)(y * multy) * 0.1)); */
		if (data->MAXCOUNT > 30)
			data->MAXCOUNT -= 10;
	}
	if(key == 1)
	{
		data->Jc[0] += 0.04;
		data->Jc[1] += 0.04;
	}
	if(key == 3)
	{
		data->Jc[0] -= 0.04;
		data->Jc[1] -= 0.04;
	}
	fractal (data);
	ft_printf("%d\n", key);
	/* write(1, "o\n", 2); */

	fractal (data);
	ft_printf("%d\n", key);
}

int	keys(int key, t_data *data)
{
	if (key == 65307)
	{
		exit_fract(data);
	}
	if (key == 65361)
	{
		data->maxR += (data->maxR - data->minR) * 0.05;
		data->minR += (data->maxR - data->minR) * 0.05;
	}
	if (key == 65362)
	{
		data->maxI += (data->maxI - data->minI) * 0.05;
		data->minI += (data->maxI - data->minI) * 0.05;
	}
	if (key == 65363)
	{
		data->maxR -= (data->maxR - data->minR) * 0.05;
		data->minR -= (data->maxR - data->minR) * 0.05;
	}
	if (key == 65364)
	{
		data->maxI -= (data->maxI - data->minI) * 0.05;
		data->minI -= (data->maxI - data->minI) * 0.05;
	}
	if (key == 113)
		data->col_chg *= 10;
	if (key == 101)
		data->col_chg /= 10;
	ft_printf("%d\n", key);
	fractal(data);
}

void	hooks(t_data *data)
{
	mlx_mouse_hook(data->win_ptr, zoom, data);
	mlx_key_hook(data->win_ptr, keys, data);
	mlx_hook(data->win_ptr, 17, 0, exit_fract, data);
}