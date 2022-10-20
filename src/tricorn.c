#include "../include/fract_ol.h"

void	tricorn(t_data *data)
{
	data->cx = ((double)data->x * data->xscale) + data->minR;
	data->cy = ((double)data->y * data->yscale) + data->minI;
	data->zx = 0;
	data->zy = 0;
	data->count = 0;
	while ((((data->zx * data->zx) + (data->zy * data->zy)) < 4) && (data->count < data->MAXCOUNT))
	{
		data->tempx = (data->zx * data->zx) - (data->zy * data->zy) + data->cx;
		data->zy = (-2 * data->zx * data->zy) + data->cy;
		data->zx = data->tempx;
		data->count++;
	}
}