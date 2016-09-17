/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 06:22:00 by aviau             #+#    #+#             */
/*   Updated: 2016/09/17 03:50:32 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		mouse(int x, int y, t_e *data)
{
	if (data->do_move)
	{
		printf("x : %d - y : %d\n", x, y);
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
			data->lasty = y;
			data->yy--;
		}
		if (y > data->lasty)
		{
			data->lasty = y;
			data->yy++;
		}
	}
	return (0);	
}

int		keyboard(int key, t_e *data)
{
	printf("key : \e[36m%d\e[0m\nx : \e[35m%d\e[0m - y  : \e[35m%d\e[0m - rot : \e[32m%f\e[0m\nxx : \e[31m%d\e[0m - yy  : \e[31m%d\e[0m - h : \e[31m%f\e[0m\n\n", key, data->x, data->y, data->rot, data->xx, data->yy, data->h);
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
		data->h += 0.1;
	if (key == 78) // -
		data->h -= 0.1;
	else if (key == 12)
	{
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
	return (0);
}

void	draw_grid(int g[10][10], t_e *d)
{
	int i;
	int j;
	double x;
	double y;
	int x2;
	int y2;

	mlx_hook(d->win, 2, (1L<<0), &keyboard, d);
	mlx_hook(d->win, 6, (1L<<13), &mouse, d);

	j = -1;
	while (++j < d->jmax)
	{
		i = -1;
		while (++i < d->imax)
		{
			x = d->ymax + ((i - 5) * d->xx * cos(d->rot)) - ((j - 5) * d->xx * sin(d->rot));
			y = d->ymax - ((i - 5) * d->yy * sin(d->rot)) - ((j - 5) * d->yy * cos(d->rot)) - g[i][j] * d->h;
			if (i < d->imax - 1)
			{
				x2 = d->ymax + ((i - 5 + 1) * d->xx * cos(d->rot)) - ((j - 5) * d->xx * sin(d->rot));
				y2 = d->ymax - ((i - 5 + 1) * d->yy * sin(d->rot)) - ((j - 5) * d->yy * cos(d->rot)) - g[i + 1][j] * d->h;
				draw_line(d, x + d->x, y + d->y, x2 + d->x, y2 + d->y, g[i + 1][j]);
			}
			if (j < d->jmax - 1)
			{
				x2 = d->ymax + ((i - 5) * d->xx * cos(d->rot)) - ((j - 5 + 1) * d->xx * sin(d->rot));
				y2 = d->ymax - ((i - 5) * d->yy * sin(d->rot)) - ((j - 5 + 1) * d->yy * cos(d->rot)) - g[i][j + 1] * d->h;
				draw_line(d, x + d->x, y + d->y, x2 + d->x, y2 + d->y, g[i][j + 1]);
			}
		}
	}
}

int		lapin(void* v_data)
{
	int i = 0;
	t_e		*data = (t_e *)v_data;
	mlx_clear_window(data->mlx, data->win);
	draw_grid((data->grid), data);
	return(0);
}

int	main(int ac, char **av)
{
	t_e	data;
	int **grid;
	if (ac != 2)
		parse(NULL, &data);
	grid = parse(av[1], &data);
	data.xx = 15;
	data.yy = 7;
	data.ymax = 500;
	data.h = 1;
	data.mlx = mlx_init();
	data.grid = (void *)&grid;
	data.rot = (float)57.2958;
	data.win = mlx_new_window(data.mlx, 1000, 1000, "fdf");
	mlx_loop_hook(data.mlx, &lapin, &data);
	mlx_loop(data.mlx);
}
