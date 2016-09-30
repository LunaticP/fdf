/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 06:22:00 by aviau             #+#    #+#             */
/*   Updated: 2016/09/30 04:20:32 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		fdf_loop(t_e *d)
{
	mlx_hook(d->win, 2, (1L << 0), &keypress, d);
	mlx_hook(d->win, 3, (1L << 1), &keyrel, d);
	mlx_hook(d->win, 6, (1L << 13), &mouse, d);
	return (0);
}

void	init2(t_e *d)
{
	d->r_s = 0;
	d->r_e = 128;
	d->g_s = 255;
	d->g_e = 64;
	d->b_s = 0;
	d->b_e = 0;
}

t_e		init(void)
{
	t_e	d;

	d.x = 625;
	d.y = 625;
	d.scl = 50;
	d.fov = 60;
	d.zz = 0.5;
	d.imax = 0;
	d.jmax = 0;
	d.zbufmax = 500;
	d.shadow = 1;
	d.m.x.x = 1;
	d.m.x.y = 0;
	d.m.x.z = 0;
	d.m.y.x = 0;
	d.m.y.y = 1;
	d.m.y.z = 0;
	d.m.z.x = 0;
	d.m.z.y = 0;
	d.m.z.z = -0.1;
	d.do_shadow = 0;
	d.do_color = 0;
	init2(&d);
	return (d);
}

int		main(int ac, char **av)
{
	t_e	d;

	if (ac != 2)
		parse(NULL, &d);
	d = init();
	d.name = ft_strdup(av[1]);
	parse(av[1], &d);
	d.mlx = mlx_init();
	d.win = mlx_new_window(d.mlx, 2400, 1350, "fdf");
	d.image = mlx_new_image(d.mlx, 2400, 1350);
	d.addr = mlx_get_data_addr(d.image, &d.bpp, &d.l_size, &d.endian);
	draw_grid(&d);
	mlx_loop_hook(d.mlx, &fdf_loop, &d);
	mlx_loop(d.mlx);
}
