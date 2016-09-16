/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 06:22:00 by aviau             #+#    #+#             */
/*   Updated: 2016/09/16 12:12:27 by aviau            ###   ########.fr       */
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
	ft_putnbr(key);
	ft_putchar(' ');
	if (key == 123) // left
		data->x -= 5;
	if (key == 124) // right
		data->x += 5;
	if (key == 126) // up
		data->y -= 5;
	if (key == 125) // down
		data->y += 5;
	if (key == 67) // *
	{
		data->xx++;
		data->ymax++;
	}
	if (key == 75) // /
	{
		data->xx--;
		data->ymax--;
	}
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
	return (0);
}

void	draw_grid(int grid[10][10], t_e *data)
{
	int i;
	int j;
	double x;
	double y;
	int x2;
	int y2;

	mlx_hook(data->win, 2, (1L<<0), &keyboard, data);
	mlx_hook(data->win, 6, (1L<<13), &mouse, data);

	j = -1;
	while (++j < 10)
	{
		i = -1;
		while (++i < 10)
		{
			x = data->ymax + (i * data->xx * cos(data->rot)) - (j * data->xx * sin(data->rot));  // 7 = value of ?
			y = data->ymax - (i * data->yy * sin(data->rot)) - (j * data->yy * cos(data->rot)) - grid[i][j] * data->h;
			if (i < 9)
			{
				x2 = data->ymax + ((i + 1) * data->xx * cos(data->rot)) - (j * data->xx * sin(data->rot));  // 7 = value of ?
				y2 = data->ymax - ((i + 1) * data->yy * sin(data->rot)) - (j * data->yy * cos(data->rot)) - grid[i + 1][j] * data->h;
				draw_line(data, x + data->x, y + data->y, x2 + data->x, y2 + data->y, grid[i + 1][j]);
			}
			if (j < 9)
			{
				x2 = data->ymax + (i * data->xx * cos(data->rot)) - ((j + 1) * data->xx * sin(data->rot));  // 7 = value of ?
				y2 = data->ymax - (i * data->yy * sin(data->rot)) - ((j + 1) * data->yy * cos(data->rot)) - grid[i][j + 1] * data->h;
				draw_line(data, x + data->x, y + data->y, x2 + data->x, y2 + data->y, grid[i][j + 1]);
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
	int grid[10][10] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 10, 10, 10, 10, 10, 10, 10, 10, 0},
		{0, 10, 20, 15, 12, 15, 17, 20, 10, 0},
		{0, 10, 15, 10, 12, 15, 15, 15, 10, 0},
		{0, 5, 15, 10, 12, 15, 15, 15, 10, 0},
		{0, 5, 10, 5, 7, 12, 12, 12, 10, 0},
		{0, 5, 7, 1, 2, 7, 5, 5, 7, 0},
		{0, 3, 0, 0, 1, 2, 2, 2, 5, 0},
		{0, 1, 0, 0, 0, 0, 0, 0, 3, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
	data.xx = 15;
	data.yy = 7;
	data.ymax = 250;
	data.h = 1;
	data.mlx = mlx_init();
	data.grid = (void *)&grid;
	data.rot = atoi(av[1]) / (float)57.2958;
	data.win = mlx_new_window(data.mlx, 1000, 1000, "fdf");
	mlx_loop_hook(data.mlx, &lapin, &data);
	mlx_loop(data.mlx);
}
