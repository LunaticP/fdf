/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 06:22:00 by aviau             #+#    #+#             */
/*   Updated: 2017/08/14 15:06:54 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <sys/time.h>

int 	compare(int **a, int **b)
{
	for (int i = 0; i < 128; i++) {
		for (int j = 0; j < 128; j++){
			if (a[i][j] != b[i][j])
				return (0);
		}
	}
	return (1);
}

void	transition(t_e *d)
{
	struct timeval	time;
	int	i;
	int j;
	int	x;

	gettimeofday(&time, NULL);
	srandom(time.tv_sec + time.tv_usec);
	if (time.tv_sec % 5)
		perlin(d->noise);
	x = random() % 5000;
	for (int num = 0; num < x; num++) {
		i = random() % 128;
		j = random() % 128;
		if (d->noise[i][j] > d->save[i][j] && d->noise[i][j] > d->grid[i][j])
			d->grid[i][j] += 1;
		else if (d->noise[i][j] < d->save[i][j] && d->noise[i][j] < d->grid[i][j])
			d->grid[i][j] -= 1;
		else
			d->grid[i][j] = d->noise[i][j];
	}
}

int		fdf_loop(t_e *d)
{
//	struct timeval	time;
//	double			t;
//
//	gettimeofday(&time, NULL);
//	t = time.tv_sec * 1000000 + time.tv_usec;
	d->z = d->zz;// * cos(t / 200000.0);
	key_color(d->key, d, (d->key & PSHIFT) ? 1 : 0, (d->key & P_CTRL) ? 1 : 0);
	key_sclfov_trans(d->key, d);
	key_rotx(d->key, d);
	key_roty(d->key, d);
	key_rotz(d->key, d);
	transition(d);
	draw_grid(d);
	disp_data(d);
	return (0);
}

void	init2(t_e *d)
{
	d->r_s = 100;
	d->r_e = 255;
	d->g_s = 100;
	d->g_e = 255;
	d->b_s = 100;
	d->b_e = 255;
}

t_e		init(void)
{
	t_e	d;

	d.x = W / 2;
	d.y = H / 2;
	d.scl = 2;
	d.fov = 60;
	d.zz = -0.1;
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
	d.l.x = 255.0f;
	d.l.y = 75.0f;
	d.l.z = -100.0f;
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
/*	for (int i = 0; i < 256; i++) {
		for (int j = 0; j < 256; j++) {
			ft_putnbr(d.grid[i][j]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}*/
	d.mlx = mlx_init();
	d.win = mlx_new_window(d.mlx, W, H, "fdf");
	d.image = mlx_new_image(d.mlx, W, H);
	d.addr = mlx_get_data_addr(d.image, &d.bpp, &d.l_size, &d.endian);
	d.grid = perlin(NULL);
	d.save = (int **)ft_memalloc(sizeof(int *) * 128);
	for (int k = 0; k < 128; k++)
		d.save[k] = (int *)ft_memalloc(sizeof(int) * 128);
	for (int i = 0; i < 128; i++) {
		for (int j = 0; j < 128; j++){
			d.save[i][j] = d.grid[i][j];
		}
	}
	d.noise = perlin(NULL);
	draw_grid(&d);
	mlx_hook(d.win, 2, (1L << 0), &keypress, &d);
	mlx_hook(d.win, 3, (1L << 1), &keyrel, &d);
	mlx_hook(d.win, 6, (1L << 13), &mouse, &d);
	mlx_loop_hook(d.mlx, &fdf_loop, &d);
	mlx_loop(d.mlx);
}
