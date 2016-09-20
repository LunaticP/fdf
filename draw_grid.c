/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 14:51:29 by aviau             #+#    #+#             */
/*   Updated: 2016/09/20 10:40:32 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		c_x(t_e *d, double j, double i)
{
	double	x;
	double	y;
	double	z;
	int		a;
	int		b;

	a = j;
	b = i;
	j -= (d->jmax - 1) / 2;
	i -= (d->imax - 1) / 2;
	x = i;
	y = j * cos(d->rotx) - (double)d->grid[a][b] * sin(d->rotx);
	z = j * sin(d->rotx) + (double)d->grid[a][b] * cos(d->rotx);
	return ((x + y + z) * d->xx);
}

int		c_y(t_e *d, double j, double i)
{
	double	x;
	double	y;
	double	z;
	int		a;
	int		b;

	a = j;
	b = i;
	j -= (d->jmax - 1) / 2;
	i -= (d->imax - 1) / 2;
	x = i * cos(d->roty) + ((double)d->grid[a][b] * d->z) * sin(d->roty);
	y = j;
	z = (i * sin(d->roty) * -1) + ((double)d->grid[a][b] * d->z) * cos(d->roty);
	return ((x + y + z) * d->yy);
}

int		c_z(t_e *d, double j, double i)
{
	double	x;
	double	y;
	int		z;
	int		a;
	int		b;

	a = j;
	b = i;
	j -= (d->jmax - 1) / 2;
	i -= (d->imax - 1) / 2;
	x = i * cos(d->rotz) - j * sin(d->rotz);
	y = i * sin(d->rotz) + j * cos(d->rotz);
	z = d->grid[a][b];
	return (x + y + z);
}

void	draw_grid(t_e *d)
{
	int		i;
	int		j;
	t_draw	X;

	mlx_destroy_image(d->mlx, d->image);
	d->image = mlx_new_image(d->mlx, 1000, 1000);
	d->addr = mlx_get_data_addr(d->image, &d->bpp, &d->l_size, &d->endian);
	j = 0;
	X.z = 10;
	while (j < d->jmax)
	{
		i  = 0;
		while (i < d->imax)
		{
		//	printf("%d ", d->grid[j][i]);
//			X.x = d->ymax + ((j - ((double)(d->jmax - 1) / 2)) * d->xx *
//			cos(d->rotx))  - ((i - ((double)(d->imax - 1) / 2)) * d->xx *
//			sin(d->rotx)) + d->x;
//			X.y = d->ymax - ((j - ((double)(d->jmax - 1) / 2)) * d->yy *
//			sin(d->rotx)) - ((i - ((double)(d->imax - 1) / 2)) * d->yy *
//			cos(d->rotx)) - d->grid[j][i] * d->zz + d->y;

			X.x = d->ymax + c_x(d, j, i) + d->x;
			X.y = d->ymax - c_y(d, j, i) + d->y;
			if (i < d->imax)
			{
				X.x2 = d->ymax + c_x(d, j, i + 1) + d->x;
				draw_line(d, &X);
			}
			else if (j < d->jmax)
			{
				X.y2 = d->ymax - c_y(d, j + 1, i) + d->y;
				draw_line(d, &X);
			}
			i++;
		}
		j++;
	}
	mlx_put_image_to_window (d->mlx, d->win, d->image, 0, 0);
}
