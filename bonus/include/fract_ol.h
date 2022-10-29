/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:14:51 by vtrevisa          #+#    #+#             */
/*   Updated: 2022/10/27 04:19:19 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include <mlx.h>
# include "../../Libft/Include/libft.h"
# include <stdlib.h>
# include <stdio.h>
# define MAXX 800
# define MAXY 600

typedef struct s_data
{
	int		maxcount;
	int		fract;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_adr;
	int		bit_per_pix;
	int		line_len;
	int		endian;
	int		color;
	double	minr;
	double	mini;
	double	maxr;
	double	maxi;
	double	xscale;
	double	yscale;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	jc[2];
	double	tempx;
	int		x;
	int		y;
	int		count;
	double	col_chg;
}	t_data;

void	init(t_data *data);
void	fractal(t_data *data);
void	hooks(t_data *data);
void	mandelbrot(t_data *data);
int		handle_args(int argc, char **argv, t_data *data);
int		exit_fract(t_data *data);
void	julia(t_data *data);
void	arg_err(int err);
void	tricorn(t_data *data);
void	menu(t_data *data);
void	zoom_in(double multx, double multy, t_data *data, int x, int y);
void	move_ur(t_data *data, int flag);
void	move_ld(t_data *data, int flag);
#endif