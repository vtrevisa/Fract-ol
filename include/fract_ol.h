#ifndef FRACT_OL_H
# define FRACT_OL_H
#include <mlx.h>
#include "../Libft/Include/libft.h"
#include <stdlib.h>

typedef struct s_data
{
	int		fract;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_adr;
	int		bit_per_pix;
	int		line_len;
	int		endian;
	int		maxx;
	int		maxy;
	int		color;
	double	minR;
	double	minI;
	double	maxR;
	double	maxI;
	double	xscale;	//Escala do eixo x
	double	yscale;	//Escala do eixo y
	double	zx;		//Z_real(Zn^2)
	double	zy;		//Z_imag(Zn^2)
	double	cx;		//C_real
	double	cy;		//C_imag
	double	Jc[2];
	double	tempx;	//Resultado de Zn+1
	int		x;		//Coordenada x do pixel
	int		y;		//Coordenada y do pixel
	int		count;	//Numero de iterações
	int		MAXCOUNT;
	double		col_chg;
} t_data;

void	init(t_data *data);
void	fractal(t_data *data);
void	hooks(t_data *data);
void	mandelbrot(t_data *data);
int		handle_args(int argc, char **argv, t_data *data);
int		exit_fract(t_data *data);
void	julia(t_data *data);
void	arg_err(int err);
void	tricorn(t_data *data);
void	menu (t_data *data);
#endif