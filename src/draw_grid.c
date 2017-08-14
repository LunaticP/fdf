/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 14:51:29 by aviau             #+#    #+#             */
/*   Updated: 2017/08/14 12:23:36 by aviau            ###   ########.fr       */
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
	x->x3 = x->tx3 * (d->m.x.x) + x->ty3 * (d->m.y.x) + x->tz3 * (d->m.z.x);
	x->y3 = x->tx3 * (d->m.x.y) + x->ty3 * (d->m.y.y) + x->tz3 * (d->m.z.y);
	x->z3 = x->tx3 * (d->m.x.z) + x->ty3 * (d->m.y.z) + x->tz3 * (d->m.z.z);
	coef = (x->z + d->fov * 20) / (d->fov * 10);
	x->x /= coef;
	x->y /= coef;
	x->z /= coef;
	coef = (x->z2 + d->fov * 20) / (d->fov * 10);
	x->x2 /= coef;
	x->y2 /= coef;
	x->z2 /= coef;
	coef = (x->z3 + d->fov * 20) / (d->fov * 10);
	x->x3 /= coef;
	x->y3 /= coef;
	x->z3 /= coef;
}

void	calc(t_e *d, t_draw *x, int j, int i)
{
	x->tx = ((float)i - ((float)(d->imax - 1) / 2)) * d->scl;
	x->ty = ((float)j - ((float)(d->jmax - 1) / 2)) * d->scl;
	x->tz = (float)d->grid[j][i] * d->z * d->scl;
	x->c = abs(d->grid[j][i]);
	if (j < d->jmax - 1 && i < d->imax - 1)
	{
		x->tx2 = ((float)i - ((float)(d->imax - 1) / 2)) * d->scl;
		x->ty2 = ((float)j - ((float)(d->jmax - 1) / 2) + 1) * d->scl;
		x->tz2 = (float)d->grid[j + 1][i] * d->z * d->scl;
		x->tx3 = ((float)i - ((float)(d->imax - 1) / 2) + 1) * d->scl;
		x->ty3 = ((float)j - ((float)(d->jmax - 1) / 2)) * d->scl;
		x->tz3 = (float)d->grid[j][i + 1] * d->z * d->scl;
		x->c2 = abs(d->grid[j + 1][i]);
		calc2(d, x);
		if (x->z >= -(d->fov * 30) && x->z2 >= -(d->fov * 30) && x->z3 >= -(d->fov * 30) &&
			!((x->x + d->x <  0 && x->x2 + d->x <  0 && x->x3 + d->x <  0) ||
			  (x->x + d->x >= W && x->x2 + d->x >= W && x->x3 + d->x >= W) ||
			  (x->y + d->y <  0 && x->y2 + d->y <  0 && x->y3 + d->y <  0) ||
			  (x->y + d->y >= H && x->y2 + d->y >= H && x->y3 + d->y >= H)))
			draw_triangle(d, x);
		x->tx = ((float)i - ((float)(d->imax - 1) / 2) + 1) * d->scl;
		x->ty = ((float)j - ((float)(d->jmax - 1) / 2) + 1) * d->scl;
		x->tz = (float)d->grid[j + 1][i + 1] * d->z * d->scl;
		x->c2 = abs(d->grid[j + 1][i + 1]);
		calc2(d, x);
		if (x->z >= -(d->fov * 30) && x->z2 >= -(d->fov * 30) && x->z3 >= -(d->fov * 30) &&
			!((x->x + d->x <  0 && x->x2 + d->x <  0 && x->x3 + d->x <  0) ||
			  (x->x + d->x >= W && x->x2 + d->x >= W && x->x3 + d->x >= W) ||
			  (x->y + d->y <  0 && x->y2 + d->y <  0 && x->y3 + d->y <  0) ||
			  (x->y + d->y >= H && x->y2 + d->y >= H && x->y3 + d->y >= H)))
			draw_triangle(d, x);
	}
}

void	draw_grid(t_e *d)
{
	int		i;
	int		j;
	t_draw	x;

	mlx_destroy_image(d->mlx, d->image);
	d->image = mlx_new_image(d->mlx, W, H);
	d->addr = mlx_get_data_addr(d->image, &d->bpp, &d->l_size, &d->endian);
	j = 0;
	for (int b = 0; b < W * H; b++)
		x.z_buf[b] = 100000.0f;
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
