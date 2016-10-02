/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 14:51:29 by aviau             #+#    #+#             */
/*   Updated: 2016/10/01 05:39:55 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	calc2(t_e *d, t_draw *x)
{
	float	coef;

	x->x = x->tx * (d->m.x.x) + x->ty * (d->m.y.x) + x->tz * (d->m.z.x);
	x->y = x->tx * (d->m.x.y) + x->ty * (d->m.y.y) + x->tz * (d->m.z.y);
	x->z = x->tx * (d->m.x.z) + x->ty * (d->m.y.z) + x->tz * (d->m.z.z);
	x->x2 = x->tx2 * (d->m.x.x) + x->ty2 * (d->m.y.x) + x->tz2 * (d->m.z.x);
	x->y2 = x->tx2 * (d->m.x.y) + x->ty2 * (d->m.y.y) + x->tz2 * (d->m.z.y);
	x->z2 = x->tx2 * (d->m.x.z) + x->ty2 * (d->m.y.z) + x->tz2 * (d->m.z.z);
	coef = (x->z + d->fov * 20) / (d->fov * 10);
	x->x /= coef;
	x->y /= coef;
	coef = (x->z2 + d->fov * 20) / (d->fov * 10);
	x->x2 /= coef;
	x->y2 /= coef;
}

void	calc(t_e *d, t_draw *x, int j, int i)
{
	x->tx = ((float)i - ((float)(d->imax - 1) / 2)) * d->scl;
	x->ty = ((float)j - ((float)(d->jmax - 1) / 2)) * d->scl;
	x->tz = (float)d->grid[j][i] * d->zz * d->scl;
	x->c = abs(d->grid[j][i]);
	if (j < d->jmax - 1)
	{
		x->tx2 = ((float)i - ((float)(d->imax - 1) / 2)) * d->scl;
		x->ty2 = ((float)j - ((float)(d->jmax - 1) / 2) + 1) * d->scl;
		x->tz2 = (float)d->grid[j + 1][i] * d->zz * d->scl;
		x->c2 = abs(d->grid[j + 1][i]);
		calc2(d, x);
		if (x->z >= -(d->fov * 20) && x->z2 >= -(d->fov * 20))
			draw_line(d, x);
	}
	if (i < d->imax - 1)
	{
		x->tx2 = ((float)i - ((float)(d->imax - 1) / 2) + 1) * d->scl;
		x->ty2 = ((float)j - ((float)(d->jmax - 1) / 2)) * d->scl;
		x->tz2 = (float)d->grid[j][i + 1] * d->zz * d->scl;
		x->c2 = abs(d->grid[j][i + 1]);
		calc2(d, x);
		if (x->z >= -(d->fov * 20) && x->z2 >= -(d->fov * 20))
			draw_line(d, x);
	}
}

void	draw_grid(t_e *d)
{
	int		i;
	int		j;
	t_draw	x;

	mlx_destroy_image(d->mlx, d->image);
	d->image = mlx_new_image(d->mlx, 2400, 1350);
	d->addr = mlx_get_data_addr(d->image, &d->bpp, &d->l_size, &d->endian);
	j = 0;
	while (j < d->jmax)
	{
		i = 0;
		while (i < d->imax)
		{
			calc(d, &x, j, i);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->image, 0, 0);
}
