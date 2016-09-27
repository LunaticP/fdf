/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 14:51:29 by aviau             #+#    #+#             */
/*   Updated: 2016/09/27 02:45:43 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	c_x(t_e *d, t_draw *x)
{
	x->x = x->tx;
	x->y = x->ty * cos(d->rotx) - x->tz * sin(d->rotx);
	x->z = x->ty * sin(d->rotx) + x->tz * cos(d->rotx);
	x->x2 = x->tx2;
	x->z2 = x->ty2 * sin(d->rotx) + x->tz2 * cos(d->rotx);
	x->y2 = x->ty2 * cos(d->rotx) - x->tz2 * sin(d->rotx);
}

void	c_y(t_e *d, t_draw *x)
{
	float xtmp;
	float ytmp;
	float ztmp;

	xtmp = x->x;
	ytmp = x->y;
	ztmp = x->z;
	x->x = xtmp * cos(d->roty) + ztmp * sin(d->roty);
	x->y = ytmp;
	x->z = xtmp * sin(d->roty) * -1 + ztmp * cos(d->roty);
	xtmp = x->x2;
	ytmp = x->y2;
	ztmp = x->z2;
	x->x2 = xtmp * cos(d->roty) + ztmp * sin(d->roty);
	x->z2 = xtmp * sin(d->roty) * -1 + ztmp * cos(d->roty);
	x->y2 = ytmp;
}

void	c_z(t_e *d, t_draw *x)
{
	float xtmp;
	float ytmp;
	float ztmp;

	xtmp = x->x;
	ytmp = x->y;
	ztmp = x->z;
	x->x = xtmp * cos(d->rotz) - ytmp * sin(d->rotz);
	x->y = xtmp * sin(d->rotz) + ytmp * cos(d->rotz);
	x->z = ztmp;
	xtmp = x->x2;
	ytmp = x->y2;
	ztmp = x->z2;
	x->x2 = xtmp * cos(d->rotz) - ytmp * sin(d->rotz);
	x->y2 = xtmp * sin(d->rotz) + ytmp * cos(d->rotz);
	x->z2 = ztmp;
}

void	calc(t_e *d, t_draw *x, int j, int i)
{
	x->tx = ((float)i - ((float)(d->imax - 1) / 2)) * d->scl;
	x->ty = ((float)j - ((float)(d->jmax - 1) / 2)) * d->scl;
	x->tz = (float)d->grid[j][i] * d->zz * d->scl;
	if (j < d->jmax - 1)
	{
		x->tx2 = ((float)i - ((float)(d->imax - 1) / 2)) * d->scl;
		x->ty2 = ((float)j - ((float)(d->jmax - 1) / 2) + 1) * d->scl;
		x->tz2 = (float)d->grid[j + 1][i] * d->zz * d->scl;
		c_x(d, x);
		c_y(d, x);
		c_z(d, x);
		draw_line(d, x);
	}
	if (i < d->imax - 1)
	{
		x->tx2 = ((float)i - ((float)(d->imax - 1) / 2) + 1) * d->scl;
		x->ty2 = ((float)j - ((float)(d->jmax - 1) / 2)) * d->scl;
		x->tz2 = (float)d->grid[j][i + 1] * d->zz * d->scl;
		c_x(d, x);
		c_y(d, x);
		c_z(d, x);
		draw_line(d, x);
	}
}

void	draw_grid(t_e *d)
{
	int		i;
	int		j;
	t_draw	x;

	mlx_destroy_image(d->mlx, d->image);
	d->image = mlx_new_image(d->mlx, 1000, 1000);
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
