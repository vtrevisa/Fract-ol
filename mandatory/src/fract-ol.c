/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:13:39 by vitor             #+#    #+#             */
/*   Updated: 2022/10/27 04:20:59 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.fract = handle_args(argc, argv, &data);
	init(&data);
	fractal(&data);
	hooks(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
