/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:07:26 by vtrevisa          #+#    #+#             */
/*   Updated: 2022/10/29 14:03:12 by vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	zoom_in(t_data *data, int x, int y)
{
		data->multx = (data->maxr - data->minr);
		data->multy = (data->maxi - data->mini);
		data->minr += data->multx * (x / (double)MAXX) / 10;
		data->mini += data->multy * (y / (double)MAXY) / 10;
		data->maxi -= data->multy * (1 - y / (double)MAXY) / 10;
		data->maxr -= data->multx * (1 - x / (double)MAXX) / 10;
		data->maxcount += 10;
}

void	move_ur(t_data *data, int flag)
{
	if (flag == 1)
	{
		data->maxi += (data->maxi - data->mini) * 0.05;
		data->mini += (data->maxi - data->mini) * 0.05;
	}
	if (flag == 2)
	{
		data->maxr -= (data->maxr - data->minr) * 0.05;
		data->minr -= (data->maxr - data->minr) * 0.05;
	}
}

void	move_ld(t_data *data, int flag)
{
	if (flag == 1)
	{
		data->maxr += (data->maxr - data->minr) * 0.05;
		data->minr += (data->maxr - data->minr) * 0.05;
	}
	if (flag == 2)
	{
		data->maxi -= (data->maxi - data->mini) * 0.05;
		data->mini -= (data->maxi - data->mini) * 0.05;
	}
}
