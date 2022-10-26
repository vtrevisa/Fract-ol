#include "../include/fract_ol.h"
#include <stdio.h>

int	zoom(int key, int x, int y, t_data *data)
{
	double multx, multy;
	if (key == 4)
	{
		multx = (data->maxR - data->minR);
		multy = (data->maxI - data->minI);
		data->minR += multx * (x / (double)MAXX) / 10;
		data->minI += multy * (y / (double)MAXY) / 10;
		data->maxI -= multy * (1 - y / (double)MAXY) / 10;
		data->maxR -= multx * (1 - x / (double)MAXX) / 10;
		data->maxcount += 10;
	}
	if (key == 5)
	{
		data->minR -= (data->maxR - data->minR) * 0.1;/* (data->minR - ((double)(x * multx) / 0.1)); */
		data->minI -= (data->maxI - data->minI) * 0.1;/* (data->minI - (((double)(MAXY - y) * multy) * 0.1)); */
		data->maxI += (data->maxI - data->minI) * 0.1;/* (data->maxI + (((double)(MAXX - x) * multx) * 0.1)); */
		data->maxR += (data->maxR - data->minR) * 0.1;/* (data->maxR + ((double)(y * multy) * 0.1)); */
		if (data->maxcount > 30)
			data->maxcount -= 10;
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