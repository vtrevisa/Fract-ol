/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 03:52:39 by vtrevisa          #+#    #+#             */
/*   Updated: 2022/11/01 15:30:01 by vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	exit_fract(t_data *data)
{		
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free (data->mlx_ptr);
	exit(0);
}

void	arg_err(int err)
{
	if (err == 1)
	{
		ft_printf("Escolha um dos fractais abaixo:\n");
		ft_printf("->\033[0;31mMandelbrot\033[0m\n");
		ft_printf("->\033[0;31mJulia\033[0m\n");
		ft_printf("->\033[0;31mTricorn\033[0m\n");
		exit(0);
	}
	else if (err == 2)
	{
		ft_printf("Fractal incompatível, escolha entre os abaixo \
										e verifique a escrita:\n");
		ft_printf("->\033[0;31mMandelbrot\033[0m\n");
		ft_printf("->\033[0;31mJulia\033[0m\n");
		ft_printf("->\033[0;31mTricorn\033[0m\n");
		exit(0);
	}
	else if (err == 3)
	{
		ft_printf("Parâmetros incompatíveis, insira os parâmetros \
													como o exemplo:\n");
		ft_printf("->\033[0;31m./fractol Julia <valor 1> <valor 2>\033[0m\n");
		exit(0);
	}
}

int	handle_args(int argc, char **argv, t_data *data)
{
	if (argc < 2)
		arg_err(1);
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
		return (1);
	if (ft_strncmp(argv[1], "Julia", 10) == 0)
	{
		if (argc < 4)
		{
			arg_err(3);
		}
		data->jc[0] = ft_atof(argv[2]);
		data->jc[1] = ft_atof(argv[3]);
		return (2);
	}
	if (ft_strncmp(argv[1], "Tricorn", 10) == 0)
		return (3);
	else
		arg_err (2);
}
