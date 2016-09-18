/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 06:22:00 by aviau             #+#    #+#             */
/*   Updated: 2016/09/19 01:06:14 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	draw_grid(int **g, t_e *d)
{
	int i;
	int j;
	double x;
	double y;
	int x2;
	int y2;

	i = -1;
	mlx_destroy_image(d->mlx, d->image);
	d->image = mlx_new_image(d->mlx, 2000, 1250);
	d->addr = mlx_get_data_addr(d->image, &d->bpp, &d->l_size, &d->endian);
	while (++i < d->jmax)
	{
		j = -1;
		while (++j < d->imax)
		{
			x = d->ymax + ((i - ((double)(d->jmax - 1) / 2)) * d->xx * cos(d->rot))  - ((j - ((double)(d->imax - 1) / 2)) * d->xx * sin(d->rot));
			y = d->ymax - ((i - ((double)(d->jmax - 1) / 2)) * d->yy * sin(d->rot)) - ((j - ((double)(d->imax - 1) / 2)) * d->yy * cos(d->rot)) - g[i][j] * d->h;
			if (i < d->jmax - 1)
			{
				x2 = d->ymax + ((i - ((double)(d->jmax - 1) / 2) + 1) * d->xx * cos(d->rot)) - ((j - ((double)(d->imax - 1) / 2)) * d->xx * sin(d->rot));
				y2 = d->ymax - ((i - ((double)(d->jmax - 1) / 2) + 1) * d->yy * sin(d->rot)) - ((j - ((double)(d->imax - 1) / 2)) * d->yy * cos(d->rot)) - g[i + 1][j] * d->h;
				draw_line(d, x + d->x, y + d->y, x2 + d->x, y2 + d->y, g[i][j], g[i + 1][j]);
			}
			if (j < d->imax - 1)
			{
				x2 = d->ymax + ((i - ((double)(d->jmax - 1) / 2)) * d->xx * cos(d->rot)) - ((j - ((double)(d->imax - 1) / 2) + 1) * d->xx * sin(d->rot));
				y2 = d->ymax - ((i - ((double)(d->jmax - 1) / 2)) * d->yy * sin(d->rot)) - ((j - ((double)(d->imax - 1) / 2) + 1) * d->yy * cos(d->rot)) - g[i][j + 1] * d->h;
				draw_line(d, x + d->x, y + d->y, x2 + d->x, y2 + d->y, g[i][j], g[i][j + 1]);
			}
		}
	}
//	printf ("x = %f   y = %f   rot = %f\nxx = %d   yy = %d   h = %f\n", x, y, d->rot, d->xx, d->yy, d->h);
	mlx_put_image_to_window(d->mlx, d->win, d->image, 0, 0);
}

int		mouse(int x, int y, t_e *data)
{
	if (data->do_move)
	{
		if (x < data->lastx)
		{
			data->rot -= 0.0174533 * (data->lastx - x);
			data->lastx = x;
		}
		if (x > data->lastx)
		{
			data->rot += 0.0174533 * (x - data->lastx);
			data->lastx = x;
		}
		if (y < data->lasty)
		{
			data->yy -= 0.0174533 * (data->lasty - y);
			data->lasty = data->yy;
		}
		if (y > data->lasty)
		{
			data->yy += 0.0174533 * (y - data->lasty);
			data->lasty = data->yy;
		}
	}
	mlx_clear_window(data->mlx, data->win);
	draw_grid(data->grid, data);
	return (0);	
}

int		keyboard(int key, t_e *data)
{
//	printf("key : \e[36m%d\e[0m\n", key);
	if (key == 123) // left
		data->x -= 5;
	if (key == 124) // right
		data->x += 5;
	if (key == 126) // up
		data->y -= 5;
	if (key == 125) // down
		data->y += 5;
	if (key == 67) // *
		data->xx++;
	if (key == 75) // /
		data->xx--;
	if (key == 69) // +
		data->h += 1;
	if (key == 78) // -
		data->h -= 1;
	else if (key == 12)
	{
//		mlx_destroy_image (data->mlx, data->image);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (key == 86)
		data->rot -= 0.0174533 * 3;
	if (key == 88)
		data->rot += 0.0174533 * 3;
	if (key == 84)
		data->yy--;
	if (key == 91)
		data->yy++;
	if (key == 49)
		data->do_move = 1;
	else if (key == 53)
		data->do_move = 0;
	if (key == 87)
	{
		data->x = 30;
		data->y = 50;
		data->xx = 52;
		data->yy = 20;
		data->h = 13;
		data->rot = 5.040033;
	}
	mlx_clear_window(data->mlx, data->win);
	mlx_string_put(data->mlx, data->win, 50, 50, 0xFFFF00,"Coucou");
	draw_grid(data->grid, data);
	return (0);
}


int		lapin(t_e *data)
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
	data.x = 30;
	data.y = 50;
	data.xx = 52;
	data.yy = 20;
	data.h = 3;
	data.rot = 5.040033;
	data.h_max = 0;
	parse(av[1], &data);
	data.ymax = 625;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 2000, 1250, "fdf");
	data.image = mlx_new_image(data.mlx, 2000, 1250);
	data.addr = mlx_get_data_addr(data.image, &data.bpp, &data.l_size, &data.endian);
	draw_grid(data.grid, &data);
	mlx_loop_hook(data.mlx, &lapin, &data);
	mlx_loop(data.mlx);
}
