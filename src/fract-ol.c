#include "../include/fract_ol.h"


int	main(int argc, char **argv)
{
	t_data data;
	
	data.fract = handle_args(argc, argv, &data);
	/* ft_printf("%d\n", data.fract); */
	init(&data);
	fractal(&data);
	hooks(&data);
	mlx_loop(data.mlx_ptr);
	return(0);
}