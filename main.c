/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 06:22:00 by aviau             #+#    #+#             */
/*   Updated: 2016/09/15 08:32:44 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_grid(int grid[10][10], t_e *data)
{
	int i;
	int j;
	double x;
	double y;
	int x2;
	int y2;

	j = -1;
	while (++j < 10)
	{
		i = -1;
		while (++i < 10)
		{
			x = 200 + (i * 15 * cos(data->rot)) - (j * 15 * sin(data->rot));  // 7 = value of ?
			y = 200 - (i * 10 * sin(data->rot)) - (j * 10 * cos(data->rot)) - grid[i][j] * 5;
			if (i < 9)
			{
				x2 = 200 + ((i + 1) * 15 * cos(data->rot)) - (j * 15 * sin(data->rot));  // 7 = value of ?
				y2 = 200 - ((i + 1) * 10 * sin(data->rot)) - (j * 10 * cos(data->rot)) - grid[i + 1][j] * 5;
				draw_line(data, x, y, x2, y2);
			}
			if (j < 9)
			{
				x2 = 200 + (i * 15 * cos(data->rot)) - ((j + 1) * 15 * sin(data->rot));  // 7 = value of ?
				y2 = 200 - (i * 10 * sin(data->rot)) - ((j + 1) * 10 * cos(data->rot)) - grid[i][j + 1] * 5;
				draw_line(data, x, y, x2, y2);
			}
		}
	}
}

int		lapin(void* v_data)
{
	int i = 0;
	t_e		*data = (t_e *)v_data;
	mlx_clear_window(data->mlx, data->win);
	data->rot += 0.0174533;
	while(++i < 1000000);
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
	data.mlx = mlx_init();
	data.grid = (void *)&grid;
	data.rot = atoi(av[1]) / (float)57.2958;
	data.win = mlx_new_window(data.mlx, 500, 500, "fdf");
	mlx_loop_hook(data.mlx, &lapin, &data);
	mlx_loop(data.mlx);
}
