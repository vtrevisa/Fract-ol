#include "../include/fract_ol.h"

void	julia(t_data *data)
{
	data->zx = (data->x * data->xscale) + data->minR;
	data->zy = (data->y * data->yscale) + data->minI;
	data->cx = data->Jc[0]/* data->Jc[0] */;
	data->cy = data->Jc[1]/* data->Jc[1] */;
	data->count = 0;
	while ((((data->zx * data->zx) + (data->zy * data->zy)) < 4) && (data->count < data->maxcount))
	{
		data->tempx = (data->zx * data->zx) - (data->zy * data->zy) + data->cx;
		data->zy = (2 * data->zx * data->zy) + data->cy;
		data->zx = data->tempx;
		data->count++;
	}
}