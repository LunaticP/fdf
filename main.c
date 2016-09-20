/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 06:22:00 by aviau             #+#    #+#             */
/*   Updated: 2016/09/20 10:39:13 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		fdf_loop(t_e *data)
{
	static int  loop = 0;
	mlx_hook(data->win, 2, (1L<<0), &keyboard, data);
	mlx_hook(data->win, 6, (1L<<13), &mouse, data);
	return(0);
}

int	main(int ac, char **av)
{
	t_e	data;

	if (ac != 2)
		parse(NULL, &data);
	data.x = 500;
	data.y = 500;
	data.xx = 0;
	data.yy = 0;
	data.zz = 0;
	data.rotx = 5.040033;
	data.roty = 5.040033;
	data.rotz = 5.040033;
	data.ymax = 250;
	parse(av[1], &data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1000, 1000, "fdf");
	data.image = mlx_new_image(data.mlx, 1000, 1000);
	data.addr = mlx_get_data_addr(data.image, &data.bpp, &data.l_size, &data.endian);
	draw_grid(&data);
	mlx_loop_hook(data.mlx, &fdf_loop, &data);
	mlx_loop(data.mlx);
}
