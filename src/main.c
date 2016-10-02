/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 06:22:00 by aviau             #+#    #+#             */
/*   Updated: 2016/10/01 12:31:11 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		fdf_loop(t_e *d)
{
	mlx_hook(d->win, 2, (1L << 0), &keypress, d);
	mlx_hook(d->win, 3, (1L << 1), &keyrel, d);
	mlx_hook(d->win, 6, (1L << 13), &mouse, d);
	key_color(d->key, d, (d->key & PSHIFT) ? 1 : 0, (d->key & P_CTRL) ? 1 : 0);
	key_sclfov_trans(d->key, d);
	key_rotx(d->key, d);
	key_roty(d->key, d);
	key_rotz(d->key, d);
	draw_grid(d);
	disp_data(d);
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

	d.x = 1200;
	d.y = 675;
	d.scl = 50;
	d.fov = 60;
	d.zz = -0.5;
	d.imax = 0;
	d.jmax = 0;
	d.m.x.x = 0.817374;
	d.m.x.y = -0.187947;
	d.m.x.z = 0.544589;
	d.m.y.x = 0.451567;
	d.m.y.y = 0.796020;
	d.m.y.z = -0.403037;
	d.m.z.x = -0.357754;
	d.m.z.y = 0.575350;
	d.m.z.z = 0.735516;
	d.do_color = 0;
	d.key = 0;
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
