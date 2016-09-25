/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 06:22:00 by aviau             #+#    #+#             */
/*   Updated: 2016/09/25 06:33:59 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	fdf_loop(t_e *d)
{
	mlx_hook(d->win, 2, (1L << 0), &keyboard, d);
	mlx_hook(d->win, 6, (1L << 13), &mouse, d);
	return (0);
}

int	main(int ac, char **av)
{
	t_e	d;

	if (ac != 2)
		parse(NULL, &d);
	d.x = 500;
	d.y = 500;
	d.xx = 5;
	d.yy = 5;
	d.zz = 5;
	d.rotx = 5.040033;
	d.roty = 5.040033;
	d.rotz = 5.040033 * 2;
	d.xmax = 500;
	d.ymax = 500;
	parse(av[1], &d);
	ft_putstr("Parse done!\n");
	d.mlx = mlx_init();
	d.win = mlx_new_window(d.mlx, 1000, 1000, "fdf");
	d.image = mlx_new_image(d.mlx, 1000, 1000);
	d.addr = mlx_get_data_addr(d.image, &d.bpp, &d.l_size, &d.endian);
	draw_grid(&d);
	mlx_loop_hook(d.mlx, &fdf_loop, &d);
	mlx_loop(d.mlx);
}
