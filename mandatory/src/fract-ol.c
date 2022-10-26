/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:13:39 by vitor             #+#    #+#             */
/*   Updated: 2022/10/26 19:13:40 by vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"


int	main(int argc, char **argv)
{
	t_data data;
	
	data.fract = handle_args(argc, argv, &data);
	init(&data);
	fractal(&data);
	hooks(&data);
	mlx_loop(data.mlx_ptr);
	return(0);
}